# ML2 - Data Preprocessing and Algorithm Selection

## 2.1 - Exploring the Data and Replacing Incorrect Values

In SAS Viya's Model Studio, the Data Exploration node is in the Miscellaneous group.

The Imputation node replaces missing values in datasets. Simple schemes replace the missing value with the mean or mode.

## 2.2 - Extracting Features

Most text data is unstructured and must be handled differently.

The Text Mining node processes text data in a document collection. Text mining helps extract meanings, patterns, and structure hidden in textual data.

The Text Mining node creates a new input column for each topic that it discovers.

## 2.3 - Transforming Inputs

Transformations are one way to handle extreme or unusual values.

Transformations allow us to
- Change the shape of a distribution by stretching or compressing it.
- Reduce the effect of outliers or heavy tails.
- Standardize inputs to be on the same range or scale.

The Transformations node in Model Studio allows us to transform input variables.

Binning is a type of transformation that can be used with categorical variables.

The transformations for variables are specified in the Data tab, and then are performed in the Transformations node.

## 2.4 - Selecting Features

Variable selection allows us to reduce the number of input variables. This helps us avoid overfitting, and reduces the number of observations necessary for statistically significant results.

The Variable Selection node has a Reason column. If the value in this column is blank for an input, that means that the variable was selected.

## 2.5 - Best Practices in Data Preparation

To address biased and incomplete data, sparsity, and high-dimensionality, the following can be done:
- Take time to understand business problem in context.
- Enrich the data.
- Select or extract features to reduce data dimensions.
- Change the representation of the data by applying appropriate transformations.
