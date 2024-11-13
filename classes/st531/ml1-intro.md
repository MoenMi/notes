# ML1 - Intro

## 1.1 - Machine Learning in Business Decision Making

The analytics life cycle represents a series of activities to extract value from raw data:
1. Data
    - Explore and prepare your data for analysis
2. Discovery
    - Detect something previously unknown
    - Build and refine multiple models
    - Select the best model
3. Deployment
    - Scoring

## 1.2 - Supervised Prediction: Preparing the Data and Building the Initial Model

The inputs in a predictive model can be called:
- predictors
- features
- explanatory features
- independent variables

The outputs can be called the:
- reponse
- outcome
- dependent variable

Variables in a model can be either **numeric (interval)** (discrete or continuous) or **categorical** (nominal, ordinal, or binary).

The training data informs the **model**, which is a concise representation of the association between the inputs and the target. The model creates predictions, can be of the following types:
- Decisions
- Rankings
- Estimates

### Data Preparation and Preprocessing

Essential data tasks:
- Divide the data
- Address rare events
- Manage missing values
- Replace incorrect values
- Add unstructured data
- Extract features
- Handle extreme or unusual values
- Select useful inputs

#### Divide the Data

Input data that is too complex will have high variance and lead to overfitting. Input data that is not complex enough will have high bias and lead to underfitting.

An input dataset is typically partitioned into the following:
- Training
- Validation
- Test (Optional) - Used to select the champion model

Any transformations or values should be generated only from the training dataset.

#### Address Rare Events

To address rare events, you should address all of the rare cases and only some of the common cases. This allows for a smaller overall case count, but similar predictive power.

#### Manage Missing Values

If the missing values are random, consider dropping rows that contain missing values. Note that this will reduce the amount of training data. This is called a **complete case analysis**.

If the missing values might be predictive, consider creating a missing indicator and using it as an input.

Missingness can be handled in the following ways:
- Naive Bayes
- Decision trees
- Missing markers
- Imputation
- Binning
- Scoring missing data

## 1.3 - A Closer Look at SAS Viya

`caslib` provides access to files in a data source and to in-memory tables.
