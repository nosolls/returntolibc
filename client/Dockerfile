# Based on jupyter base notebook
FROM jupyter/base-notebook:61d8aaedaeaf

# File Creator
MAINTAINER Noah Oller Smith <nosolls@protonmail.com>

USER root

# Updates and installs needed packages for user
RUN apt update && \
	apt install -y \
	gcc \
	gdb \
	git \
	nasm

# Installs PEDA 
RUN git clone https://github.com/longld/peda.git ~/peda
RUN echo "source ~/peda/peda.py" >> ~/.gdbinit

# Allows user to run certain commands under sudo
ADD hackersudo /etc/sudoers.d/
RUN chmod 0400 /etc/sudoers.d/hackersudo

# Copies files to directory
COPY --chown=1000:100 retlib.c $HOME/
COPY --chown=1000:100 exploit.c $HOME/
COPY --chown=1000:100 getbinsh.c $HOME/

# Sets directory for client
WORKDIR $HOME

CMD ["start-notebook.sh","--NotebookApp.token="]
