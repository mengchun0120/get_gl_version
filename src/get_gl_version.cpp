#include <iostream>
#include <stdexcept>
#include <string>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

using namespace std;

void initGLFW()
{
    if (!glfwInit())
    {
        throw runtime_error("glfwInit failed");
    }
}

void setWindowHints()
{
    glfwWindowHint(GLFW_SAMPLES, 4);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *createWindow(unsigned int width,
                         unsigned int height,
                         const std::string& title)
{
    GLFWwindow *window = glfwCreateWindow(width, height, title.c_str(),
                                          nullptr, nullptr);
    if (!window)
    {
        throw runtime_error("glfwCreateWindow failed");
    }

    return window;
}

void makeContextCurrent(GLFWwindow *window)
{
    glfwMakeContextCurrent(window);
}

void setupInputMode(GLFWwindow *window)
{
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
}

void initGLEW()
{
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK)
    {
        throw runtime_error("glewInit failed");
    }
}

void showVersion()
{
    const GLubyte* glversion = glGetString(GL_VERSION);
    if (!glversion)
    {
        throw runtime_error("glGetString(GL_VERSION) failed");
    }

    cout << "Version: " << glversion << endl;

    const GLubyte* glslversion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    if (!glslversion)
    {
        throw runtime_error("glGetString(GL_SHADING_LANGUAGE_VERSION) failed");
    }

    cout << "GLSL Version: " << glslversion << endl;
}

void run(GLFWwindow* window)
{
    while (0 == glfwWindowShouldClose(window))
    {
        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main(int argc, char* argv[])
{
    try
    {
        initGLFW();
        setWindowHints();
        GLFWwindow* window = createWindow(400, 400, "Get GL Version");
        makeContextCurrent(window);
        setupInputMode(window);
        initGLEW();
        showVersion();
        run(window);
    }
    catch (const exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
