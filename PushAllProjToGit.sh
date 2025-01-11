#!/bin/bash

# Base directory
BASE_DIR="$HOME/QR_Sync"

# Project directories
PROJECTS=("CgenMin" "AAAConfigProj" "QR_Core" "templateprojectwev")

# Ask for commit message
echo "Enter the commit message: "
read -r COMMIT_MSG

# Iterate through each project directory
for PROJECT in "${PROJECTS[@]}"; do
  PROJECT_PATH="$BASE_DIR/$PROJECT"
  
  # Check if the directory exists
  if [ -d "$PROJECT_PATH" ]; then
    echo "Processing $PROJECT..."
    cd "$PROJECT_PATH" || { echo "Failed to access $PROJECT_PATH"; continue; }
    
    # Check if it is a git repository
    if [ -d ".git" ]; then
      git add .
      git commit -m "$COMMIT_MSG"
      git push
    else
      echo "Skipping $PROJECT_PATH: Not a git repository."
    fi
  else
    echo "Skipping $PROJECT: Directory not found."
  fi
done

echo "All projects processed."

