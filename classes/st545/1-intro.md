# 1 - Intro

## Statistical Learning Problem Examples

- Identify the risk factors for prostate cancer.
- Classify a recorded phenome based on a log-periodogram.
- Predict whether someone will have a heart attack on the basis of demographic, diet, and clinical measurements.
- Customize an email spam detection system.
- Identify the numbers in a handwritten zip code.
- Classify a tissue sample into one of several cancer classes, based on a gene expression profile.
- Establish the relationship between salary and demographic variables in population survey data.
- Classify the pixels in a LANDSAT image, by usage.

## Fundamentals of Statistical Learning

### Starting Point

- Outcome measurement $Y$ (also called dependent variable, response, target).
- Vector of $p$ predictor measurements $X$ (also called inputs, regressors, covariates, features, independent variables).
- In the **regression problem**, $Y$ is quantitative (e.g. price, blood pressure).
- In the **classification problem**, $Y$ takes value in a finite, unordered set (survived/died, digit 0-9, cancer class of tissue sample).
- We have training data $(x_1, y_1), \dots, (x_N, y_N)$. These are observations (examples, instances) of these measurements.

### Objectives

On the basis of training data we would like to:
- Accurately predict unseen test cases.
- Understand which inputs affect the outcome, and how.
- Assess the quality of our predictions and inferences.

### Philosophy

- It is important to understand the ideas behind the various techniques, in order to know how and when to use them.
- One has to understand the simpler methods first, in order to grasp the more sophisticated ones.
- It is important to accurately assess the performance of a method, to know how well or how badly it is working (simpler methods often perform as well as fancier ones).
- This is an exciting research area, having important applications in science, industry, and finance.
- Statistical learning is a fundamental ingredient in the training of a modern data scientist.

### Unsupervised Learning

- No outcome variable, just a set of predictors (features) measured on a set of samples.
- Objective is more fuzzy: find groups of samples that behave similarly, find features that behave similarly, find linear combinations of features with the most variation.
- Difficult to know how well you're doing.
- Different from supervised learning, but can be useful as a pre-processing step for supervised learning.

## Statistical Learning vs. Machine Learning

- Machine learning arose as a subfield of Artificial Intelligence.
- Statistical learning arose as a subfield of statistics.
- There is much overlap; both fields focus on supervised and unsupervised problems:
  - Machine learning has a greater emphasis on large scale applications and prediction accuracy.
  - Statistical learning emphasizes models and their interpretability, and precision and uncertainty.
- But the distinction has become more and more blurred, and there is a great deal of cross-fertilization.
- Machine learning has the upper hand in marketing.
