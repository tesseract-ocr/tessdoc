# Overview of the new neural network system in Tesseract 4.00

*   [Introduction](#introduction)
*   [Integration with Tesseract](#integration-with-tesseract)
*   [Hardware and CPU requirements](#hardware-and-cpu-requirements)
*   [For Open Source Contributors](#for-open-source-contributors)
*   [Basics of the Implementation](#basics-of-the-implementation)
*   [Adding a new Layer Type](#adding-a-new-layer-type)

# Introduction

Tesseract 4.00 includes a new neural network subsystem configured as a textline
recognizer. It has its origins in OCRopus' [Python-based LSTM implementation](https://github.com/tmbdev/ocropy), but
has been totally redesigned for Tesseract in C++. The neural network system in
Tesseract pre-dates TensorFlow, but is compatible with it, as there is a
network description language called [Variable Graph Specification
Language](VGSLSpecs) (VGSL), that is also available for TensorFlow. See
https://github.com/tensorflow/models/tree/master/research/street

The idea of VGSL is that it is possible to build a neural network and train it
without having to learn a lot of anything. There is no need to learn Python,
TensorFlow, or even write any C++ code. It is merely required to understand the
VGSL specification language well enough to build syntactically correct network
descriptions. Some basic knowledge of what the various neural network layer
types are and how they are combined will go a very long way.

# Integration with Tesseract

The Tesseract 4.00 neural network subsystem is integrated into Tesseract as a
line recognizer. It can be used with the existing layout analysis to recognize
text within a large document, or it can be used in conjunction with an external
text detector to recognize text from an image of a single textline.

The neural network engine is the default for 4.00. To recognize text from an
image of a single text line, use `SetPageSegMode(PSM_RAW_LINE)`. This can be
used from the command-line with `-psm 13`

The neural network engine has been integrated to enable the multi- language mode
that worked with Tesseract 3.04, but this will be improved in a future release.
Vertical text is now supported for Chinese, Japanese and Korean, and should be
detected automatically.

# Hardware and CPU Requirements

The Tesseract 4.00 neural network subsystem is heavily compute-intensive, using
the order of ten times the CPU resources of the base Tesseract, but the impact
is mitigated, if your platform supports it, as follows:

*   OpenMP allows use of four cores in parallel if your machine has them.
*   Intel/AMD processors that support SSE and/or AVX benefit from SIMD
    parallelization of the core matrix multiplications.

On a machine with multiple cores, and AVX, an easy English image may take twice
as much real time, and use 7 times the CPU as base Tesseract, whereas Hindi
takes more CPU than base Tesseract, but actually runs faster in terms of real
time.

If the above components are missing, there is a slower plain C++ implementation
that enables the code to still work.

Little-endian and big-endian systems are both supported.

# For Open Source Contributors

The initial implementation lacks the following:

*   There is a C++ implementation if the hardware does not have SSE and/or AVX,
    but the code could benefit from SIMD implementations for other hardware,
    such as ARM. See the new `arch` directory for where to insert the code.

# Basics of the Implementation

All network layer types are derived from the `Network` base-class. The
`Plumbing` sub-class is a base-class for layers that manipulate other layers in
some way, e.g. by reshaping their input/output or organising a group of layers.

The input/output data "Tensor" is `NetworkIO` and the weights are stored in a
`WeightMatrix,` both of which contain a Tesseract `GENERIC_2D_ARRAY` to hold the
data. `LSTMRecognizer` provides the higher-level abstraction of converting an
image of a textline to a sequence of tesseract `WERD_RES` classes. `LSTMTrainer`
likewise handles the abstraction of training a network on an image of a textline
that has a UTF-8 string 'truth'. `NetworkBuilder` takes responsibility for
converting the VGSL specification language to a graph of network elements.

# Adding a new Layer Type

A new layer class must derive from `Network` or `Plumbing` and implement at
least the following virtual methods:

*   `spec`, which returns a string corresponding to the string that generated
    the layer.
*   `Serialize/DeSerialize` to save/restore the layer to/from a TFile.
*   `Forward` to run the layer in the forwards direction.
*   `Backward` to run the layer in the backwards direction during training.

Layers that have weights must also implement `Update` to update the weights with
a set of gradients. There are quite a few other methods that may need to be
implemented, depending on the specific requirements of the new layer. See
`network.h` for more information on the methods that may require implementing.

*   `NetworkBuilder` must be modified to parse the specification of the new
    type.
*   The `NetworkType` enum must be extended to include the new type.
*   A corresponding entry in `Network::kTypeNames` must be added for the new
    type.
*   `Network::CreateFromFile` must be modified to construct the appropriate type
    on deserialization.
*   As with any new code, `lstm/Makefile.am` needs to be updated with the new
    filenames.
