ARG VARIANT=3.11
FROM mcr.microsoft.com/devcontainers/python:${VARIANT}

LABEL maintainer="markus braun <markus.braun@em.ag>"

# default shell = zsh
SHELL [ "/bin/zsh", "-c" ]

# set environment
ENV PYTHONUNBUFFERED 1
ENV TZ=Europe/Berlin
ENV PATH="/home/vscode/.local/bin:${PATH}"

# Install apt dependencies
# - default-jre for running plantuml
# - graphviz for plantuml/doxygen (however that's already provided by the base image - still we have it here in case we'd switch..)
# - doxygen
# - imagemagick (sphinx dependency)
RUN apt-get update \
 && export DEBIAN_FRONTEND=noninteractive \
 && apt-get install --no-install-recommends -y \
      default-jre \
      graphviz \
      doxygen \
      imagemagick \
 && apt-get autoremove \
 && apt-get clean \
 && rm -rf /var/lib/apt/lists/*

# Update doxygen to latest
RUN wget -c https://www.doxygen.nl/files/doxygen-1.9.7.linux.bin.tar.gz -O /tmp/doxygen.tar.gz \
    && mkdir -p /tmp/doxygen \
    && tar -xzvf /tmp/doxygen.tar.gz --strip-components=1 -C /tmp/doxygen/ \
    && mv /tmp/doxygen/bin/* /usr/bin \
    && mv /tmp/doxygen/man/man1/* /usr/share/man/man1 \
    && rm -rf /tmp/doxygen/

# Install plantUML
RUN wget -c https://netcologne.dl.sourceforge.net/project/plantuml/plantuml.jar -O /tmp/plantuml.jar && \
    mkdir -p /usr/share/plantuml && \
    mv /tmp/plantuml.jar /usr/share/plantuml/plantuml.jar


# Switch to vscode user
USER vscode

# set workspace dir and ensure it's present
# set cache home directory to in-repo directory (so it will survive container rebuilds and speed up startup
# and dependency resolution)
ARG WORKSPACE_DIR
WORKDIR ${WORKSPACE_DIR}/

# set cache home directory to in-repo directory (so it will survive container rebuilds and speed up startup
# and dependency resolution)
ENV XDG_CACHE_HOME=${WORKSPACE_DIR}/.cache

# Install poetry (we're not use pipx here because poetry in a virtualenv has it's issues...)
RUN curl -sSL https://install.python-poetry.org | python3 - \
    && mkdir -p ~/.zfunc \
    && poetry completions zsh > ~/.zfunc/_poetry \
    && echo 'fpath+=~/.zfunc' >> ~/.zshrc \
    && echo 'autoload -Uz compinit && compinit' >> ~/.zshrc

# Install poetry up (to update dependencies)
RUN poetry self add poetry-plugin-up

# Install precommit globally in the container (with pipx installation we had error messages during pre-commit
# checks like "/usr/local/bin/python: No module named pre_commit" - seems it needs the python module available
# in the global python environment
RUN pip install pre-commit

# Install poethepoet (task runner for poetry)
RUN pipx install poethepoet

# Inject + Install QA tooling
RUN pipx inject flake8 flake8-bugbear flake8-comprehensions flake8-simplify cohesion pydocstyle \
    flake8-docstrings pep8-naming \
    && pipx install isort \
    && pipx install commitizen \
    && pipx install reuse

# install pytest
RUN pipx install pytest && pipx inject pytest pytest-cov pytest-emoji pytest-md

# install sphinx + themes
# RUN pipx install sphinx \
#     && pipx inject sphinx Pillow myst-parser sphinxcontrib-plantuml sphinx_design sphinx_toolbox sphinx_autoapi \
#     sphinx-copybutton sphinx-immaterial

# note that installation of dependencies and pre-commit installation will be done after vscode has started
# the container (see devcontainer.json and on_create_command.sh).
