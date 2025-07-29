FROM codercom/code-server:latest

# Switch to root for package installation
USER root

# Install LaTeX Workshop extension
RUN code-server --install-extension James-Yu.latex-workshop

# Install LaTeX and required packages
RUN apt-get update && apt-get install -y \
    texlive-full \
    texlive-latex-extra \
    texlive-fonts-extra \
    texlive-lang-indonesian \
    texlive-bibtex-extra \
    biber \
    makeindex \
    latexmk \
    && rm -rf /var/lib/apt/lists/*

# Set up LaTeX Workshop settings
RUN mkdir -p /home/coder/.local/share/code-server/User/globalStorage/James-Yu.latex-workshop
COPY latex-workshop-settings.json /home/coder/.local/share/code-server/User/globalStorage/James-Yu.latex-workshop/settings.json

# Make the build script executable
COPY build-latex.sh /usr/local/bin/build-latex.sh
RUN chmod +x /usr/local/bin/build-latex.sh

# Switch back to coder user
USER coder
