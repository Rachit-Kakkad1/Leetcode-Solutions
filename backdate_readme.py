import os
import re
import subprocess

def main():
    root_dir = os.path.abspath(".")
    
    date_pattern = re.compile(r"(\d{4}-\d{2}-\d{2})\s+(\d{2})\.(\d{2})\.(\d{2})")
    commits_made = 0
    
    for folder_name in os.listdir(root_dir):
        folder_path = os.path.join(root_dir, folder_name)
        if not os.path.isdir(folder_path) or folder_name.startswith('.'):
            continue
            
        if folder_name in ["scripts", "node_modules", "easy", "medium", "hard", "unknown"]:
            continue
            
        readme_path = os.path.join(folder_path, "README.md")
        if os.path.isfile(readme_path):
            date_str = None
            for file_name in os.listdir(folder_path):
                match = date_pattern.search(file_name)
                if match:
                    date_str = f"{match.group(1)} {match.group(2)}:{match.group(3)}:{match.group(4)}"
                    break
                    
            if date_str:
                rel_readme_path = os.path.relpath(readme_path, root_dir)
                subprocess.run(["git", "add", rel_readme_path], cwd=root_dir, check=True)
                
                env = os.environ.copy()
                env["GIT_AUTHOR_DATE"] = date_str
                env["GIT_COMMITTER_DATE"] = date_str
                
                commit_msg = f"docs: add README for {folder_name}"
                try:
                    subprocess.run(["git", "commit", "-m", commit_msg], cwd=root_dir, env=env, check=True)
                    commits_made += 1
                except subprocess.CalledProcessError:
                    pass

    print(f"\nFinished committing {commits_made} backdated READMEs.")

if __name__ == "__main__":
    main()
