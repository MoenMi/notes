# ML4 - Neural Networks

## 4.1 - Building a Default Neural Network Model

Neural networks perform well in high-dimension spaces.

The biggest issues with neural networks are their lack of interpretability and need for a strong signal.

Neural networks are universal approximators, meaning they can model any input-output relationship, no matter how complex.

A neuron network can have the following form:

$$ \hat y = \hat w_{00} + \hat w_{01} H_1 + \hat w_{02} H_2 + \hat w_{03} H_3 $$

where
- $\hat y$ is the predicted outcome
- $\hat w_{00}$ is the bias estimate
- $\hat w_{01}$ is a weight estimate
- $H_1$ is a hidden unit

## 4.2 - Modifying the Model: Network Architecture

Neural networks can add complexity through the number of layers, the number of neurons per layer, and different connection types.

Having too many hidden units will result in modeling noise. Too few hidden units will result in the failure to capture the signal.

The optimal number of hidden units is roughly twice the number of input dimensions. One way to optimize the number of hidden units is to start with few, and then add units until the network's performance drops.

## 4.3 - Modifying the Model: Network Learning and Optimization

To optimize the complexity of a neural network, the magnitude of the weights should be controlled, and we should minimize the addition or more terms or rules.

The penalty term in a neural network be either the decay parameter $\lambda$ multiplied by the sum of absolute weights, or the $\lambda$ times the sum of squared weights.

When early stopping is used, the final model comes from one of the models before the final iteration.

Network learning hyperparameters:
- learning rate
- annealing rate
- regularization terms (L1, L2)
- momentum

The learning rate specifies the step size for gradient descent optimization.
