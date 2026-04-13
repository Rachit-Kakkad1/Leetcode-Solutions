#!/usr/bin/env python3
"""
Auto-update README.md with new LeetCode problems
Run this script before pushing to GitHub
"""

import os
import re
from pathlib import Path

def get_problem_number(folder_name):
    """Extract problem number from folder name"""
    match = re.match(r'^(\d+)', folder_name)
    return int(match.group(1)) if match else 0

def get_problem_name(folder_name):
    """Extract problem name from folder name"""
    # Remove number prefix and clean up
    name = re.sub(r'^\d+-', '', folder_name)
    name = name.replace('-', ' ')
    return name.title()

def update_readme():
    """Update the README with all problem folders"""
    
    root = Path('.')
    readme_path = root / 'README.md'
    
    # Get all problem folders
    folders = []
    for item in root.iterdir():
        if item.is_dir() and not item.name.startswith('.'):
            # Check if folder has any solution files
            files = list(item.glob('*'))
            code_files = [f for f in files if f.suffix in ['.py', '.cpp', '.js', '.c', '.java']]
            if code_files:
                folders.append((item.name, item))
    
    # Sort by problem number
    folders.sort(key=lambda x: get_problem_number(x[0]))
    
    # Build problems table
    problems_md = "| # | Problem | Folder |\n|---|---------|--------|\n"
    for folder_name, _ in folders:
        num = get_problem_number(folder_name)
        name = get_problem_name(folder_name)
        problems_md += f"| {num} | {name} | [{folder_name}](./{folder_name}) |\n"
    
    # Read current README
    readme_content = readme_path.read_text(encoding='utf-8')
    
    # Find and replace the problems section
    start_marker = "<!-- Problems list"
    end_marker = "<!-- AUTO-GENERATED END -->"
    
    start_idx = readme_content.find(start_marker)
    end_idx = readme_content.find(end_marker)
    
    if start_idx != -1 and end_idx != -1:
        # Replace problems section
        new_readme = (
            readme_content[:start_idx] +
            f"<!-- Problems list - Auto-updated by GitHub Actions -->\n" +
            problems_md +
            readme_content[end_idx:]
        )
        
        # Update stats
        total = len(folders)
        new_readme = new_readme.replace(
            "| Total | Solved | Rate |",
            f"| {total} | {total} | 100% |"
        )
        
        # Write back
        readme_path.write_text(new_readme, encoding='utf-8')
        print(f"Updated README with {total} problems!")
    else:
        print("Warning: Markers not found - please check README format")

if __name__ == "__main__":
    update_readme()