# ImGui 🖼

An sample project of using ImGui.

## Using GLFW

In my Triangle project, I used GLUT.
However, starting the ImGui example in GLUT, I saw some comment about GLUT saying

```
// !!! Nowadays, prefer using GLFW or SDL instead!
```

So I've decided to uses GLFW instead 🙂

### Installing the GLFW library in MacOS
Use Homebrew to install the libraries.

```
brew install glfw glew glm
```

Follow the instructions on **[With CMake and installed GLFW binaries](https://www.glfw.org/docs/3.3/build_guide.html#build_link_cmake_package)**

Download files from **[Glad](https://glad.dav1d.de/)**

I was helped by this [Tutorial](https://decovar.dev/blog/2019/08/04/glfw-dear-imgui/).
Thank you!!!