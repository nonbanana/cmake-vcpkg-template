# 모던 C++ CMake 템플릿
[![en](https://img.shields.io/badge/lang-en-green.svg)](./readme.md)
[![ko](https://img.shields.io/badge/lang-ko-red.svg)](./readme.ko.md)

**vcpkg**를 사용하는 C++ 프로젝트용 모던 CMake 템플릿입니다. 크로스 컴파일, 문서화, CI/CD 환경을 지원합니다.

## 주요 기능

- CMake 프리셋
- vcpkg 매니페스트 모드
- vcpkg 바이너리 캐시를 활용한 GitHub Actions
- [WIP] amd64-aarch64 크로스 컴파일
- [WIP] 도큐먼트 생성 및 GitHub Pages 배포

## 설명

이 프로젝트는 vcpkg를 이용해 의존성을 설치하고, `libhajime`라는 공유 라이브러리와 `hajime-cli` 실행 파일을 생성합니다.  
`hajime-cli`를 `--input 이미지_경로` 인수와 함께 실행하면, 캐니 엣지(Canny edge)를 적용한 이미지가 출력됩니다.

![example](./todoroki_hajime.png)

**하지메(はじめ)**는 일본어로 *"처음, 시작"*이라는 의미이며, 제가 좋아하는 홀로라이브 소속 탈렌트 [토도로키 하지메](https://hololive.hololivepro.com/en/talents/todoroki-hajime/)의 이름이기도 합니다.

## 사전 준비

- CMake (3.31 버전에서 테스트됨)
- GCC 및 G++ (13 버전에서 테스트됨)
- Ninja
- Git
- pkgconf (리눅스 전용)
  - 윈도우에서는 vcpkg가 자동으로 빌드함
- Doxygen (선택 사항)

## 문제 해결

### ❗ Snap CMake 버전 관련 오류

현재 `CMake 4.0.0`은 `OpenCV 4.10.0`을 빌드할 수 없습니다.  
vcpkg는 PATH에 있는 CMake 대신 snap으로 설치된 CMake를 사용할 수 있으며, snap은 자동 업데이트되기 때문에 4.0.0으로 올라가 빌드 오류가 발생할 수 있습니다.

Snap으로 설치된 CMake 여부 확인:

```bash
snap info cmake
```

이미 다른 방식으로 설치된 CMake가 있다면 snap을 제거하세요:

```bash
snap remove cmake
```

구버전으로 변경:

```bash
snap refresh cmake --channel=3.31/stable
```

처음부터 설치할 경우:

```bash
snap install cmake --classic --channel=3.31/stable
```