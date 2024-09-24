
FROM fedora:latest

RUN dnf install --assumeyes \
    make \
    gcc \
    valgrind \
    curl \
    vim \
    zsh \
    git \
    && rm -rf /var/cache/pacman/pkg/*

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

CMD ["zsh"]
