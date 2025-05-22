FROM codercom/code-server:latest

# Install LaTeX Workshop extension
RUN code-server --install-extension James-Yu.latex-workshop
