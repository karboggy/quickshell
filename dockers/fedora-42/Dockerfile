FROM fedora:42

# linux: basic tools
RUN dnf -y install \
        which

# quickshell: basic dependencies
RUN dnf -y install \
        cmake \
        qt6-qtbase-devel \
        qt6-qtdeclarative-devel \
        qt6-qtshadertools-devel \
        spirv-tools \
        spirv-tools-devel \
        pkg-config \
        cli11-devel \
        qt6-qtwayland-devel \
        qt6-qtsvg-devel \
        ninja

# quickshell: Crash Reporter (breakpad)
# RUN dnf -y copr enable @fedora-review/fedora-review-2372509-breakpad
# RUN dnf -y install breakpad
# -DCRASH_REPORTER=OFF

# quickshell: Jemalloc
RUN dnf -y install jemalloc-devel

# quickshell: Wayland
RUN dnf -y install wayland-devel wayland-protocols-devel

# quickshell: Foreign Toplevel Management
RUN dnf -y install libdrm-devel mesa-libgbm-devel

# quickshell: X11
RUN dnf -y install libxcb-devel

# quickshell: Pipewire
RUN dnf -y install pipewire-devel

# quickshell: MPRIS (usually part of qt6base)

# quickshell: PAM
RUN dnf -y install pam-devel

# linux: clean
RUN dnf clean all

# linux: you should bind the local code source directory to /quickshell
WORKDIR /quickshell

# default entrypoint is configure and build
ENTRYPOINT ["/bin/sh", "-c", "cmake -GNinja -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -DDISTRIBUTOR=karbo-fork -DCRASH_REPORTER=OFF && cmake --build build"]

# ----------
# HOW TO
# ----------
# docker build -f ./dockers/fedora-42/Dockerfile -t quickshell-fedora-42:latest ./dockers/fedora-42/ 
# docker run --rm -it --user $(id -u):$(id -g) -v "$(pwd)":/quickshell -w /quickshell quickshell-fedora-42:latest
# ----------

# ----------
# TIPS
# ----------
# docker run --rm -it --entrypoint /bin/bash --user $(id -u):$(id -g) -v "$(pwd)":/quickshell -w /quickshell quickshell-fedora-42:latest
# cmake -GNinja -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo -DDISTRIBUTOR=karbo-fork -DCRASH_REPORTER=OFF
# cmake --build build
# cmake --install build
# ----------