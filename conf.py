"""sphinx configuration file."""

# pylint: disable=invalid-name

import datetime
import glob
import os
import re
import sys
from typing import Any, Dict, List

sys.path.append(os.path.abspath("."))

# == Helper functions ==================================================================================================


def version_from_project_toml() -> str:
    """Get the version number from project.toml file."""
    with open("pyproject.toml", "r") as toml:
        text = toml.read()
        matches = re.findall(r"^version = ['\"](\d+\.\d+\.\d+)['\"]", text, flags=re.MULTILINE)
        return matches[0]


def multi_glob(*glob_patterns: str) -> List[str]:
    """Expand the glob_patterns to a list of matching files/directories.

    :return: A list of matching files/directories.
    :rtype: List[str]
    """
    result = []
    for p in glob_patterns:
        for path in glob.glob(p):
            result.append(path)
    return result


def last_updated_from_git() -> str:
    """Get the last updated string from git command (needs a git repository!).

    :return: The last updated string
    :rtype: str
    """
    git_cmd_timestamp = ["git", "log", "--pretty=format:'%ad'", "--date=local", "-n1"]
    git_cmd_commit = ["git", "log", "--pretty=format:'%h'", "--date=local", "-n1"]

    import subprocess  # nosec: B404

    try:
        ts = subprocess.check_output(git_cmd_timestamp).decode("utf-8")  # nosec: B603
        commit = subprocess.check_output(git_cmd_commit).decode("utf-8")  # nosec: B603
        return f"{ts}, {commit}"
    except Exception:
        return f"{datetime.datetime.now()}, <no git commit available>"


def theme_options(theme: str) -> Dict[str, Any]:
    """Get the theme options dict for a given supported theme."""
    supported_themes = ["sphinx_book_theme", "sphinx_rtd_theme"]
    if theme not in supported_themes:
        raise Exception(f"theme {theme} is not supported by docs-as-code-demo. Must be one of {supported_themes}.")

    if theme == "sphinx_book_theme":
        return {
            "show_navbar_depth": 1,
            "collapse_navigation": True,
            "repository_url": "https://www.github.com/engineering-methods/docs-as-code-demo",
            "use_repository_button": True,
            "use_edit_page_button": False,
            "use_issues_button": False,
            "use_download_button": False,
            "repository_branch": "main",
            "home_page_in_toc": True,
        }

    elif theme == "sphinx_rtd_theme":
        return {
            "show_nav_level": 1,
            "collapse_navigation": True,
            "github_url": "https://www.github.com/engineering-methods/docs-as-code-demo",
            "repository_url": "https://www.github.com/engineering-methods/docs-as-code-demo",
            "logo_only": False,
        }
    else:
        raise Exception(f"theme '{theme}' is not supported. Please edit conf.py:theme_options function to add support.")


# == Configuration =====================================================================================================

# General information about the project.
project = "docs-as-code-demo"
html_show_copyright = False

# The version info for the project you're documenting, acts as replacement for
# |version| and |release|, also used in various other places throughout the
# built documents.
version = version_from_project_toml()
release = version_from_project_toml()

# -- General configuration ---------------------------------------------------------------------------------------------
source_suffix = ".rst"
# master_doc = "docs/index"
language = "en"
templates_path = ["docs/_templates"]

# List of patterns, relative to source directory, that match files and
# directories to ignore when looking for source files.
# This pattern also affects html_static_path and html_extra_path .
exclude_patterns = multi_glob(
    ".*",
    "_*",
    "dist",
    "docs/_templates",
    "docs/auto_api/index.rst",
    "NOTICE.md",
    "LICENSE.md",
    "CHANGELOG.md",
    "README.md",
    "external/README.md",
    "tests",
    "src/demo",
    "src/doxygen-awesome-css",
)

# -- Options for HTML output -------------------------------------------------------------------------------------------
# Configure HTML theme (remember to also change doxysphinx)
html_theme = "sphinx_book_theme"
html_theme_options = theme_options(html_theme)
html_static_path = ["docs/_static/"]
html_title = project
html_css_files = [f"{html_theme.replace('_', '-')}-custom.css"]
html_logo = "docs/images/docs-as-code-logo.svg"
html_favicon = "docs/images/em_favicon_512px.png"
html_last_updated_fmt = last_updated_from_git()
github_username = "anyone"  # these just need to be set that the sphinx toolbox extension will work
github_repository = "any"

# -- Sphinx extensions -------------------------------------------------------------------------------------------------
extensions = [
    "sphinxcontrib.plantuml",
    # "autoapi.extension",
    "sphinx.ext.viewcode",
    "myst_parser",
    "sphinx.ext.graphviz",
    "sphinx.ext.todo",
    "sphinx_copybutton",
    "sphinx.ext.inheritance_diagram",
    "sphinx_design",
    "sphinx_needs",
    "sphinxcontrib.jquery",
]

# Plantuml
plantuml = "java -Djava.awt.headless=true -jar /usr/share/plantuml/plantuml.jar"
plantuml_output_format = "svg"

# Autoapi (deactivated for now because we've got no python code here yet)
# autoapi_dirs = ["em/docs_as_code_demo"]
# autoapi_root = "docs/auto_api"
# autoapi_options = ["members", "undoc-members", "show-inheritance", "show-inheritance-diagram", "show-module-summary"]
# autoapi_keep_files = True
# autoapi_add_toctree_entry = False
# autodoc_typehints = "signature"

# Myst
myst_enable_extensions = ["colon_fence"]
myst_heading_anchors = 4

# Sphinx Needs
needs_types = [
    dict(directive="stk_req", title="Stakeholder Requirement", prefix="STK_REQ_", color="#BFD8D2", style="node"),
    dict(directive="sys_req", title="System Requirement", prefix="SYS_REQ_", color="#B7DBFF", style="node"),
    dict(directive="sw_req", title="Software Requirement", prefix="SW_REQ_", color="#FEDCD2", style="node"),
    dict(directive="sw_comp", title="Software Component", prefix="SW_COMP_", color="#DF744A", style="node"),
    dict(directive="sw_spec", title="Software Specification", prefix="SW_SPEC_", color="#AE198D", style="node"),
    dict(directive="sw_class", title="Implementation Class", prefix="SW_CLASS_", color="#F3FFB5", style="node"),
    dict(directive="sw_test", title="Software Test Case", prefix="SW_TEST_", color="#DCB239", style="node"),
    # Kept for backwards compatibility
    dict(directive="need", title="Need", prefix="N_", color="#9856a5", style="node"),
]
needs_extra_options = ["priority"]

needs_extra_links = [
    {"option": "depends", "incoming": "is depended on", "outgoing": "depends"},
    {"option": "requires", "incoming": "is required by", "outgoing": "requires"},
    {"option": "relates", "incoming": "is related to", "outgoing": "relates"},
    {"option": "implements", "incoming": "is implemented by", "outgoing": "implements"},
    {"option": "tests", "incoming": "is tested by", "outgoing": "tests"},
]
needs_id_required = True
needs_id_regex = r"(SW|STK|SYS)-(REQ|COMP|SPEC|TEST|CLS)-[a-zA-Z0-9]+"

# create needs json for needs vscode plugin
needs_build_json = True
