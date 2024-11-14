# ML3 - Decision Trees

Decision trees require little data preparation and are easy to interpret.

## 3.1 - Building a Default Decision Tree Model

The leaf nodes in a decision tree provide the predictions.

Each leaf node contains a decision and an estimate (percent confidence).

Regression trees are built to handle continuous target variables, as opposed to regular decision trees, which handle categorical target variables.
- Regular decision trees use metrics like Gini impurity, entropy, or misclassification error to choose splits. Regression trees use Mean Squared Error (MSE), or similar metrics.

## 3.2 - Modifying the Model: Tree Structure

A decision tree can have more than 2-way splits.

## 3.3 - Modifying the Model: Recursive Partitioning

The recursive partitioning method is a greedy, top-down partitioning method that makes locally optimal choices. At each node, the algorithm decides the best split, which is one that reduces variability and increases purity. This continues until a stopping rule prevents further growth.

The Gini index measures the probability that any two elements of a group, chosen at random and with replacement, are different. This can be used as a criterion for determining whether to split.

A node has perfect purity when it contains either all events or all non-events.

To determine how to split at a node, the following can be used:
- Pearson chi-squared
- p-value
- logworth = -log(chi-squared p-value)
- adjusted logworth

$$ \text{logworth} = -\log_{10}(\text{p-value}_{\text{chi-squared}}) $$

A **Bonferroni adjustment** adds a penalty for complexity, since increasing the number of splits increases the chance that you have a meaningless statistically significant result.

$$ \text{Bonferroni-adjusted p-value} = \frac{\text{original p-value}}{\text{number of comparisons}} $$

## 3.4 - Modifying the Model: Pruning

With no stopping rules, decision trees would grow until each observation has its own leaf.

To reduce the number of branches and leaf nodes in a tree, Model Studio uses bottom-up pruning.

Bottom-up pruning starts by identifying a sequence of candidate subtrees, one for each possible number of leaves, and then selects the best of the candidates.

Hyperparameters include maximum tree depth in a decisision tree.
