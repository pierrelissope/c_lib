
FROM archlinux:latest

RUN pacman -Sy --noconfirm \
    make \
    gcc \
    valgrind \
    curl \
    vim \
    zsh \
    git \
    && pacman -Scc --noconfirm \
    && rm -rf /var/cache/pacman/pkg/*

RUN sh -c "$(curl -fsSL https://raw.githubusercontent.com/ohmyzsh/ohmyzsh/master/tools/install.sh)"

CMD ["zsh"]
