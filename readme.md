# Modern C++ CMake Template

A modern CMake template for C++ projects using **vcpkg**, ready for cross-compilation, documentation, and CI/CD.

이 문서는 영어와 [한국어](./readme.ko.md) 버전이 제공됩니다.
[![en](https://img.shields.io/badge/lang-en-green.svg)](./readme.md)
[![ko](https://img.shields.io/badge/lang-ko-green.svg)](./readme.ko.md)

## Features

- CMake presets
- Vcpkg manifest mode
- GitHub Actions with vcpkg binary caching
- [WIP] Cross compilation (amd64 ↔ aarch64)
- [WIP] Doxygen build & GitHub Pages publishing

## Description

This project installs dependencies via vcpkg and builds a shared library called `libhajime` and an executable named `hajime-cli`.  
You can run `hajime-cli` with the `--input image_path` argument to apply Canny edge detection and output the resulting image.

![example](./todoroki_hajime.png)

**Hajime** (はじめ) means *"beginning"* in Japanese, and is also the name of one of my favorite Hololive talents: [Todoroki Hajime](https://hololive.hololivepro.com/en/talents/todoroki-hajime/).

## Prerequisites

- CMake (tested with 3.31)
- GCC & G++ (tested with 13)
- Ninja
- Git
- pkgconf (Linux only)
  - On Windows, this is built by vcpkg
- Doxygen (optional)

## Troubleshooting

### ❗ Snap CMake Version Issues

`CMake 4.0.0` currently cannot build `OpenCV 4.10.0`.  
Vcpkg may not use the same version of CMake in your system's PATH, especially when installed via **snap**. Snap CMake auto-updates, so it might upgrade to 4.0.0 and cause build errors.

Check if snap CMake is installed:

```bash
snap info cmake
```

If you already have another version installed, remove snap CMake:

```bash
snap remove cmake
```

To downgrade via snap:

```bash
snap refresh cmake --channel=3.31/stable
```

To install the desired version from scratch:

```bash
snap install cmake --classic --channel=3.31/stable
```