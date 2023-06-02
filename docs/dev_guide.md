# Developer Quickstart

In general, you should have [vscode](https://https://code.visualstudio.com/) installed (which is fully
supported by us). Alternatively you could also use any other python IDE (e.g. PyCharm), however then you're on
your own considering setup.

We provide a [dev container](https://code.visualstudio.com/docs/remote/containers) which might be a little
more frictionless (because all dependencies are installed automatically in an isolated environment) or
standard __non container development__.

What is better for you comes down to your personal preferences.

## Contribution

There are some rules to contribute to this repository. Please read the [contribution guidelines](../CONTRIBUTING.md)
before you start.

## Developing in DevContainer

Just open the repo in vscode devcontainer and follow the steps in the [Usage](#usage) section.

> ⚠ __Warning__ - if you're on windows...
>
> Be careful not to mount your windows filesystem into wsl2 / the devcontainer because this will be slow as
> hell regarding file io. This will be automatically the case if you clone your repo on a windows drive,
> open it in vscode and then open the devcontainer. Instead you can use one of the following approaches:
>
> - Clone your repo in wsl2 in the native wsl2 filesystem (not beginning with `/mnt` !!) and open it from there:
>   [Open a wsl2 folder in a container on Windows](https://code.visualstudio.com/docs/remote/containers#_open-a-wsl-2-folder-in-a-container-on-windows)
> - Clone your repo directly in a new docker volume (which also happens to live in the wsl2 filesystem):
>   [Open a git repository or github pr in an isolated container volume](https://code.visualstudio.com/docs/remote/containers#_quick-start-open-a-git-repository-or-github-pr-in-an-isolated-container-volume)
>

## Developing natively (Windows or Linux)

This is a little more work because you need to arrange prerequisites first.

### Prerequisites

- Python (see <https://python.org>) - recommended version: 3.11+
- Poetry (see <https://python-poetry.org/docs/master/#installation>)

  - ```bash
    # Linux / WSL / Mac
    curl -sSL https://install.python-poetry.org | python3 -
    ```

  - ```powershell
    # Windows (powershell)
    (Invoke-WebRequest -Uri https://install.python-poetry.org -UseBasicParsing).Content | python
    ```

## Usage

### in devcontainer - like it's intended

open vscode by typing:

```shell
code
```

When vscode opens you should see a notification asking you if you want to reload vscode in
devcontainer - acknowledge it.
(If that's not working keep sure that you installed the
[remote container extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
in vscode on your host).

### native development (windows, linux, etc.) - without devcontainer

- Open the repo in vscode
- __On first start:__ install poetry packages and precommit hooks with vscode terminal (may take some time)

  ```shell
  # install poetry dependencies
  poetry install --with docs
  # install pre-commit hooks
  pre-commit install --install-hooks
  # activate automatic update of pre-commit hooks
  pre-commit autoupdate
  ```

- in vscode select the python interpreter at `./.venv/bin/python` (created by poetry install command before) by
  - `Command Palette [F1] -> Python: Select Interpreter`
  - if the poetry virtual env created before isn't shown restart vscode and retry

## Usage / Development

- you can just hit F5 and should be able to run/debug into the code
- you can also use the testrunner (in the vscode sidebar) to run the unittests if you created some
  (or write some more for all the great features you're implementing now 😉)

- For running the {{ package_name }} cli you can also run it directly in the vscode terminal:

  ```shell
  poetry run {{ package_name }} <args...>
  ```

- For running tasks like linting, documentation generation etc. just use poe:

  ```shell
  # list tasks (available tasks are displayed at the bottom)
  poe --help

  # generate documentation (in `.build/html`)
  poe docs

  # run linting over complete project
  poe lint

  # clean build output
  poe clean

## Troubleshooting

### The devcontainer isn't starting

... and you've got no idea why because the log contains no clear error.
Sometimes this happens because of vscode/devcontainer caching.

You could try to start fresh by either:

1. Just rebuilding: <br/>`[F1]->DevContainers: Rebuild and Reopen in Container`
2. Rebuild with clearing the cache: <br/>`[F1]->DevContainers: Rebuild without Cache and Reopen in Container`
3. Do a full cleanup/reset: <br/>in repo root terminal -> `.devcontainer/reset.sh` (Note that this will also do a
   docker system prune which might affect other containers as well)

### Module not found errors

If you get module not found errors, e.g. when running {{ package_name }} the problem might be the vscode
terminal. Sometimes vscode isn't activating the poetry virtualenv correctly in terminal (even if the rest of
vscode is working). The solution is then to just restart the terminal (note that in the devcontainer you
should use the zsh terminal).

## Pycharm usage

> :bulb: Should be the same for Intellij Idea.

While we recommend using vscode there are times when pycharm may be a better fit/ may be better suited for
some dev tasks.

When opening the project in pycharm you may need to select the poetry executable. Under Windows this is
installed in `%USERPROFILE%\AppData\Roaming\Python\Scripts\poetry.exe` (This path is as the time of this
writing documented wrong in the poetry documentation so we mentioned that here).

Initialization will take some time in pycharm (especially when indexing the python sdk) so please be patient
until everything is set up (watch the right side of the pycharm status bar).
