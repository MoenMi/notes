import json
from pathlib import Path

def clean_execution_count(notebook_path):
    """Removes execution_count from a Jupyter notebook file."""
    with open(notebook_path, "r", encoding="utf-8") as f:
        nb = json.load(f)

    def remove_execution_count(cell):
        if "execution_count" in cell:
            cell["execution_count"] = None
        return cell

    if "cells" in nb:
        nb["cells"] = [remove_execution_count(cell) for cell in nb["cells"]]

    with open(notebook_path, "w", encoding="utf-8") as f:
        json.dump(nb, f, indent=1)

# Find and process all Jupyter notebooks recursively
for notebook in Path(".").rglob("*.ipynb"):
    print(f"Cleaning: {notebook}")
    clean_execution_count(notebook)

print("✅ All notebooks cleaned successfully.")
