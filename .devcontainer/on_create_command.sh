#! /usr/bin/env bash

# color definitions
C_CYAN="\e[36m"
C_LGREEN="\e[92m"
C_RESET="\e[0m"

title() {
 echo -e "$C_CYAN$1$C_RESET"
}

info() {
 echo -e "$C_LGREEN$1$C_RESET"
}

title "Running .devcontainer/on_create_command.sh..."

info "Installing poetry dependencies..."
poetry install

info "Autoupdating pre-commit hooks..."
pre-commit autoupdate

info "Installing pre-commit hooks..."
pre-commit install --install-hooks
