import os
import re
import subprocess


DATE_PATTERN = re.compile(r"^(\d{4}-\d{2}-\d{2} \d{2}\.\d{2}\.\d{2})")
SKIP_DIRS = {".git", ".github", "__pycache__"}


def run_git(args, env=None):
    subprocess.run(["git"] + args, check=True, env=env)


def git_has_staged_changes():
    result = subprocess.run(
        ["git", "diff", "--cached", "--quiet"],
        stdout=subprocess.DEVNULL,
        stderr=subprocess.DEVNULL,
    )
    return result.returncode != 0


def collect_solution_files(root):
    solutions = []

    for folder_name in sorted(os.listdir(root)):
        folder_path = os.path.join(root, folder_name)

        if not os.path.isdir(folder_path):
            continue
        if folder_name in SKIP_DIRS:
            continue

        for file_name in sorted(os.listdir(folder_path)):
            if file_name == "debug.log":
                continue

            file_path = os.path.join(folder_path, file_name)
            if not os.path.isfile(file_path):
                continue

            match = DATE_PATTERN.match(file_name)
            if not match:
                continue

            extracted_date = match.group(1).replace(".", ":")
            relative_path = os.path.join(folder_name, file_name)
            solutions.append((extracted_date, folder_name, relative_path))

    return sorted(solutions)


def main():
    root = os.getcwd()

    run_git(["init"])
    run_git(["branch", "-M", "main"])

    for extracted_date, folder_name, relative_path in collect_solution_files(root):
        run_git(["add", "--", relative_path])

        if not git_has_staged_changes():
            continue

        commit_env = os.environ.copy()
        commit_env["GIT_AUTHOR_DATE"] = extracted_date
        commit_env["GIT_COMMITTER_DATE"] = extracted_date

        run_git(["commit", "-m", f"Add solution: {folder_name}"], env=commit_env)

    print("Done! Run: git push -u origin main --force")


if __name__ == "__main__":
    main()
