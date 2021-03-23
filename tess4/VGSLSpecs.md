# VGSL Specs - rapid prototyping of mixed conv/LSTM networks for images

Variable-size Graph Specification Language (VGSL) enables the specification of a
neural network, composed of convolutions and LSTMs, that can process
variable-sized images, from a very short definition string.

## Applications: What is VGSL Specs good for?

VGSL Specs are designed specifically to create networks for:

*   Variable size images as the input. (In one or BOTH dimensions!)
*   Output an image (heat map), sequence (like text), or a category.
*   Convolutions and LSTMs are the main computing component.
*   Fixed-size images are OK too!

### Model string input and output

A neural network model is described by a string that describes the input spec,
the output spec and the layers spec in between. Example:

```
[1,0,0,3 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx256 O1c105]
```

The first 4 numbers specify the size and type of the input, and follow the
TensorFlow convention for an image tensor: [batch, height, width, depth]. Batch
is currently ignored, but eventually may be used to indicate a training
mini-batch size. Height and/or width may be zero, allowing them to be variable.
A non-zero value for height and/or width means that all input images are
expected to be of that size, and will be bent to fit if needed. Depth needs to
be 1 for greyscale and 3 for color. As a special case, a different value of
depth, and a height of 1 causes the image to be treated from input as a sequence
of vertical pixel strips. **NOTE THAT THROUGHOUT, x and y are REVERSED from
conventional mathematics,** to use the same convention as TensorFlow. The
reason TF adopts this convention is to eliminate the need to transpose images on
input, since adjacent memory locations in images increase x and then y, while
adjacent memory locations in tensors in TF, and NetworkIO in tesseract increase
the rightmost index first, then the next-left and so-on, like C arrays.

The last "word" is the output specification and takes the form:

```
O(2|1|0)(l|s|c)n output layer with n classes.
  2 (heatmap) Output is a 2-d vector map of the input (possibly at
    different scale). (Not yet supported.)
  1 (sequence) Output is a 1-d sequence of vector values.
  0 (category) Output is a 0-d single vector value.
  l uses a logistic non-linearity on the output, allowing multiple
    hot elements in any output vector value. (Not yet supported.)
  s uses a softmax non-linearity, with one-hot output in each value.
  c uses a softmax with CTC. Can only be used with s (sequence).
  NOTE Only O1s and O1c are currently supported.
```

The number of classes is ignored (only there for compatibility with TensorFlow)
as the actual number is taken from the unicharset.

## Syntax of the Layers in between

NOTE that *all* ops input and output the standard TF convention of a 4-d tensor:
`[batch, height, width, depth]` *regardless of any collapsing of dimensions.*
This greatly simplifies things, and allows the VGSLSpecs class to track changes
to the values of widths and heights, so they can be correctly passed in to LSTM
operations, and used by any downstream CTC operation.

NOTE: in the descriptions below, `<d>` is a numeric value, and literals are
described using regular expression syntax.

NOTE: Whitespace is allowed between ops.

### Functional ops

```
C(s|t|r|l|m)<y>,<x>,<d> Convolves using a y,x window, with no shrinkage,
  random infill, d outputs, with s|t|r|l|m non-linear layer.
F(s|t|r|l|m)<d> Fully-connected with s|t|r|l|m non-linearity and d outputs.
  Reduces height, width to 1. Connects to every y,x,depth position of the input,
  reducing height, width to 1, producing a single <d> vector as the output.
  Input height and width *must* be constant.
  For a sliding-window linear or non-linear map that connects just to the
  input depth, and leaves the input image size as-is, use a 1x1 convolution
  eg. Cr1,1,64 instead of Fr64.
L(f|r|b)(x|y)[s]<n> LSTM cell with n outputs.
  The LSTM must have one of:
    f runs the LSTM forward only.
    r runs the LSTM reversed only.
    b runs the LSTM bidirectionally.
  It will operate on either the x- or y-dimension, treating the other dimension
  independently (as if part of the batch).
  s (optional) summarizes the output in the requested dimension, outputting
    only the final step, collapsing the dimension to a single element.
LS<n> Forward-only LSTM cell in the x-direction, with built-in Softmax.
LE<n> Forward-only LSTM cell in the x-direction, with built-in softmax,
  with binary Encoding.
```

In the above, `(s|t|r|l|m)` specifies the type of the non-linearity:

```
s = sigmoid
t = tanh
r = relu
l = linear (i.e., No non-linearity)
m = softmax
```

Examples:

`Cr5,5,32` Runs a 5x5 Relu convolution with 32 depth/number of filters.

`Lfx128` runs a forward-only LSTM, in the x-dimension with 128 outputs, treating
the y dimension independently.

`Lfys64` runs a forward-only LSTM in the y-dimension with 64 outputs, treating
the x-dimension independently and collapses the y-dimension to 1 element.

### Plumbing ops

The plumbing ops allow the construction of arbitrarily complex graphs. Something
currently missing is the ability to define macros for generating say an
inception unit in multiple places.

```
[...] Execute ... networks in series (layers).
(...) Execute ... networks in parallel, with their output concatenated in depth.
S<y>,<x> Rescale 2-D input by shrink factor y,x, rearranging the data by
  increasing the depth of the input by factor xy.
  **NOTE** that the TF implementation of VGSLSpecs has a different S that is
  not yet implemented in Tesseract.
Mp<y>,<x> Maxpool the input, reducing each (y,x) rectangle to a single value.
```

### Full Example: A 1-D LSTM capable of high quality OCR

`[1,1,0,48 Lbx256 O1c105]`

As layer descriptions: (Input layer is at the bottom, output at the top.)

```
O1c105: Output layer produces 1-d (sequence) output, trained with CTC,
  outputting 105 classes.
Lbx256: Bi-directional LSTM in x with 256 outputs
1,1,0,48: Input is a batch of 1 image of height 48 pixels in greyscale, treated
  as a 1-dimensional sequence of vertical pixel strips.
[]: The network is always expressed as a series of layers.
```

This network works well for OCR, as long as the input image is carefully
normalized in the vertical direction, with the baseline and meanline in constant
places.

### Full Example: A multi-layer LSTM capable of high quality OCR

`[1,0,0,1 Ct5,5,16 Mp3,3 Lfys64 Lfx128 Lrx128 Lfx256 O1c105]`

As layer descriptions: (Input layer is at the bottom, output at the top.)

```
O1c105: Output layer produces 1-d (sequence) output, trained with CTC,
  outputting 105 classes.
Lfx256: Forward-only LSTM in x with 256 outputs
Lrx128: Reverse-only LSTM in x with 128 outputs
Lfx128: Forward-only LSTM in x with 128 outputs
Lfys64: Dimension-summarizing LSTM, summarizing the y-dimension with 64 outputs
Mp3,3: 3 x 3 Maxpool
Ct5,5,16: 5 x 5 Convolution with 16 outputs and tanh non-linearity
1,0,0,1: Input is a batch of 1 image of variable size in greyscale
[]: The network is always expressed as a series of layers.
```

The summarizing LSTM makes this network more resilient to vertical variation in
position of the text.

## Variable size inputs and summarizing LSTM

NOTE that currently the only way of collapsing a dimension of unknown size to
known size (1) is through the use of a summarizing LSTM. A single summarizing
LSTM will collapse one dimension (x or y), leaving a 1-d sequence. The 1-d
sequence can then be collapsed in the other dimension to make a 0-d categorical
(softmax) or embedding (logistic) output.

For OCR purposes then, the height of the input images must either be fixed, and
scaled (using Mp or S) vertically to 1 by the top layer, or to allow
variable-height images, a summarizing LSTM must be used to collapse the vertical
dimension to a single value. The summarizing LSTM can also be used with a fixed
height input.
