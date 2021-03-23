## The Hallucination Effect
Is the sensitive dependence on the initial conditions in which a small change in one state in the system can result in large differences in a later state. It's some-how connected to "The Butterfly Effect" & "The Domino Effect".

## Observing this phenomenon in Tesseract 4.x
If your training text frequently includes a certain element in a certain form.
- Example 1: A word is frequently in the Capital form **`Word`**, then when you use that trained model to recognize **`word`**, it's going to hallucinate and see it as **`Word`**.

- Example 2: Your training text frequently includes a `Space` at the beginning of your sentences or at the end. Might result in slow training, non-convergence & even model corruption.
## Conclusion
Mostly, The Hallucination Effect is a product of the text that have been used to create the `traineddata` model.
* To combat such effect, one should refrain from excessive use of a single element/form/character/ etc... 
Also, one should use a vast and diverse text input for training, while cleaning and removing the parts that you deem unnecessary, because `Neural Networks` also learn patterns & language behavior.