# Getting Started

In this guide we'll walk you through setting up and using the Demo.

## Step 0: Prerequisites

Please be sure to fulfill the following prerequisites:

- [Docker](https://docs.docker.com/get-docker/) is installed
- [VSCode](https://code.visualstudio.com/) is installed plus the
  [Dev Containers Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
  or the
  [Remote Development Extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.vscode-remote-extensionpack)
  (which is just a Pack that also includes the first one)
- [Git](https://git-scm.com/downloads) is installed

## Step 1: Installing the Demo

- Just clone/download the corresponding [Git Repository](https://github.com/engineering-methods/docs-as-code-demo)
  to your local disk.

> 💡 __Tip__ - if you're on windows...
>
> You will have a much better performance if you clone the repo into a WSL drive. If you haven't got WSL
> installed or just have no idea what WSL is then just ignore this hint... else not you can:
>
> - Clone your repo in wsl2 in the native wsl2 filesystem (not beginning with `/mnt` !!) and open it from there:
>   [Open a wsl2 folder in a container on Windows](https://code.visualstudio.com/docs/remote/containers#_open-a-wsl-2-folder-in-a-container-on-windows)
> - Clone your repo directly in a new docker volume (which also happens to live in the wsl2 filesystem):
>   [Open a git repository or github pr in an isolated container volume](https://code.visualstudio.com/docs/remote/containers#_quick-start-open-a-git-repository-or-github-pr-in-an-isolated-container-volume)
>

## Step 2: Start the Devcontainer

- Open the local repository directory in VSCode.
- You should get a message about that a Devcontainer is present -> Click on "Open in DevContainer".
  If not hit `[F1]` and type `>Dev Containers: Reopen in Devcontainer`.
- Wait for the container to load up (the first time it'll take some time)

## Step 3: Build the Demo Documentation

- If VSCode is done loading the devcontainer open a new Terminal (zsh).
- Enter `poe docs` to build the demo documentation.
- You can find the root page of the generated htmls in `.build/html/index.html`

## Done 🎉

- Now you can play around with, e.g. the `conf.py` or the documentation itself.
