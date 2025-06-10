# SQLAlchemy

This follows the SQLAlchemy Unified Tutorial: https://docs.sqlalchemy.org/en/20/tutorial/index.html

## Introduction

SQLAlchemy is presented as two distinct APIs known as **Core** and **ORM**.
- **SQLAlchemy Core** is the foundational architecture for SQLAlchemy, providing tools for managing connections to databases, interacting with queries and results, and constructing SQL statements. Tools from this API are imported from `sqlalchemy`.
- **SQLAlchemy ORM** builds upon the Core to provide **object relational mapping** capabilities. Tools from this API are imported from `sqlalchemy.orm`.

## Establishing Connectivity - the Engine


