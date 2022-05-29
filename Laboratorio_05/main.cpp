#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>
#include <cmath>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow* window);

const unsigned int SCR_WIDTH = 1280;
const unsigned int SCR_HEIGHT = 720;


const char* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"void main()\n"
"{\n"
"   gl_Position = vec4(aPos, 1.0);\n"
"}\0";

const char* fragmentShaderSource = "#version 330 core\n"
"out vec4 FragColor;\n"
"uniform vec4 ourColor;\n"
"void main()\n"
"{\n"
"   FragColor = ourColor;\n"
"}\n\0";

int main()
{
    
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif


    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);


    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }



    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = {

        - 0.58f,	0.01f,
        - 0.59f,	0.36f,
        - 0.81f,	0.37f,
        - 0.86f,	0.45f,
        - 0.78f,	0.44f,
        - 0.59f,	0.41f,
        - 0.74f,	0.55f,
        - 0.75f,	0.61f,
        - 0.67f,	0.72f,
        - 0.56f,	0.74f,
        - 0.69f,	0.87f,
        - 0.53f,	0.85f,
        - 0.42f,	0.72f,
        - 0.58f,	0.57f,
        - 0.70f,	0.59f,
        - 0.49f,	0.73f,
        - 0.27f,	0.44f,
        - 0.18f,	0.46f,
        - 0.16f,	0.43f,
        - 0.25f,	0.38f,
        - 0.44f, - 0.21f,
        - 0.13f,	0.23f,
        0.13f,	0.34f,
        0.16f,	0.15f,
        0.52f,	0.20f,
        0.35f,	0.07f,
        0.67f,	0.10f,
        0.51f,	0.00f,
        0.67f, - 0.13f,
        0.77f, - 0.10f,
        0.68f, - 0.31f,
        0.33f, - 0.11f,
        - 0.06f, - 0.14f,
        - 0.11f, - 0.22f,
        - 0.19f, - 0.24f,
        - 0.01f,	0.20f,
        - 0.26f, - 0.30f,
        - 0.22f, - 0.38f,
        - 0.34f, - 0.46f,
        - 0.28f, - 0.74f,
        - 0.38f, - 0.66f,
        - 0.42f, - 0.68f,
        - 0.47f, - 0.71f,
        - 0.47f, - 0.78f,
        - 0.43f, - 0.78f,
        - 0.43f, - 0.75f,
        - 0.38f, - 0.70f,
        - 0.33f, - 0.71f,
        - 0.36f, - 0.79f,
        - 0.39f, - 0.79f,
        - 0.38f, - 0.75f,
        0.43f, - 0.30f,
        0.63f, - 0.41f,
        0.77f, - 0.48f,
        0.69f, - 0.69f,
        0.79f, - 0.70f,
        0.64f, - 0.74f,
        0.60f, - 0.78f,
        0.60f, - 0.83f,
        0.64f, - 0.83f,
        0.68f, - 0.83f,
        0.72f, - 0.83f,
        0.74f, - 0.75f,
        0.69f, - 0.78f,
        0.64f, - 0.78f,
        0.69f, - 0.75f


    };

    unsigned int indices[] = {
        // Triangulos negros
        2, 3, 4,  
        1, 2, 5,
        4, 5, 6,
        2, 4, 5,
        12, 16, 17,
        17, 18, 19,
        18, 19, 21,
        18, 21, 22,
        21, 22, 23,
        22, 23, 24,
        23, 24, 25,
        24, 25, 26,
        25, 26, 27,
        26, 27, 28,
        26, 28, 29,
        42, 43, 44,
        44, 45, 49,
        48, 49, 50,
        57, 58, 59,
        59, 60, 64,
        60, 61, 63,

        //Triangulos naranja
        3, 4, 6,
        6, 7, 8,
        6, 8, 9,
        8, 9, 10,
        11, 12, 15,
        9, 12, 13,
        9, 13, 14,
        5, 6, 13,
        1, 12, 13,
        1, 12, 16,
        19, 20, 21,
        20, 21, 35,
        23, 32, 35,
        23, 25, 32,
        25, 31, 32,
        31, 32, 33,
        32, 33, 34,
        32, 35, 36,
        20, 35, 38,
        34, 36, 37,
        36, 37, 38,
        38, 39, 40,
        37, 38, 39,
        40, 41, 46,
        41, 45, 46,
        40, 46, 47,
        46, 47, 50,
        39, 47, 48,
        25, 27, 31,
        27, 28, 30,
        28, 29, 30, 
        27, 30, 31,
        30, 31, 51,
        30, 51, 53,
        52, 53, 54,
        53, 54, 55,
        54, 56, 64,
        54, 55, 63,
        55, 61, 62,

        //Triangulos naranja claro
        9, 11, 15,
        0, 1, 17,
        0, 19, 20,
        47, 48, 50,
        45, 46, 49,
        41, 42, 44,
        61, 62, 63,
        60, 64, 65,
        56, 57, 59,
        //Triangulos rojos
        6, 13, 14,
        54, 64, 65
    };

    unsigned int VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glUseProgram(shaderProgram);


    while (!glfwWindowShouldClose(window))
    {

        processInput(window);

        // render
        // ------
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        glBindVertexArray(VAO);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        int vertexColorLocation = glGetUniformLocation(shaderProgram, "ourColor");

        glDrawElements(GL_LINE, 2, GL_UNSIGNED_INT, 0);

        glUniform4f(vertexColorLocation, 0.145f, 0.117f, 0.129f, 0.0f);
        glDrawElements(GL_TRIANGLES, 63, GL_UNSIGNED_INT, 0);

        glUniform4f(vertexColorLocation, 1.0f, 0.545f, 0.062f, 0.0f);
        glDrawElements(GL_TRIANGLES, 117, GL_UNSIGNED_INT, (const void*)(63 * sizeof(unsigned int)));

        glUniform4f(vertexColorLocation, 1.0f, 0.749f, 0.376f, 0.0f);
        glDrawElements(GL_TRIANGLES, 27, GL_UNSIGNED_INT, (const void*)(180 * sizeof(unsigned int)));

        glUniform4f(vertexColorLocation, 0.560f, 0.082f, 0.086f, 0.0f);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (const void*)(207 * sizeof(unsigned int)));

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;

}


void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}


void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

