#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <vector>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

int m_width = 0;
int m_height = 0;

void error_callback(int error, const char* description)
{
    fprintf(stderr, "Error: %s\n", description);
}

int main()
{
    // glfw: initialize and configure
    // ------------------------------
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // to use traditional functiosn, specify compatible profile
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    // glfw window creation
    // --------------------
    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "LearnOpenGL", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetErrorCallback(error_callback);
    // glad: load all OpenGL function pointers
    // ---------------------------------------
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return -1;
    }

    std::cout << "GL version " << glGetString(GL_VERSION) << std::endl;

    // set up vertex data (and buffer(s)) and configure vertex attributes
    // ------------------------------------------------------------------
    float firstTriangle[] = {
        -0.9f, -0.5f, 0.0f,  // left 
        -0.0f, -0.5f, 0.0f,  // right
        -0.45f, 0.5f, 0.0f,  // top 
    };
    float secondTriangle[] = {
        0.0f, -0.5f, 0.0f,  // left
        0.9f, -0.5f, 0.0f,  // right
        0.45f, 0.5f, 0.0f   // top 
    };

    static glm::vec3 vertices[] = {
        {0.5f, -0.5f, 0.5f},    // front face
        {-0.5f, -0.5f, 0.5f},   // front face
        {-0.5f, -0.5f, -0.5f},  // front face
        {0.5f, -0.5f, -0.5f},   // front face

        {-0.5f, 0.5f, 0.5f},   // back face
        {0.5f, 0.5f, 0.5f},    // back face
        {0.5f, 0.5f, -0.5f},   // back face
        {-0.5f, 0.5f, -0.5f},  // back face

        {-0.5f, -0.5f, 0.5f},   // left face
        {-0.5f, 0.5f, 0.5f},    // left face
        {-0.5f, 0.5f, -0.5f},   // left face
        {-0.5f, -0.5f, -0.5f},  // left face

        {0.5f, 0.5f, 0.5f},    // right face
        {0.5f, -0.5f, 0.5f},   // right face
        {0.5f, -0.5f, -0.5f},  // right face
        {0.5f, 0.5f, -0.5f},   // right face

        {0.5f, 0.5f, 0.5f},    // top face
        {-0.5f, 0.5f, 0.5f},   // top face
        {-0.5f, -0.5f, 0.5f},  // top face
        {0.5f, -0.5f, 0.5f},   // top face

        {0.5f, -0.5f, -0.5f},   // bot face
        {-0.5f, -0.5f, -0.5f},  // bot face
        {-0.5f, 0.5f, -0.5f},   // bot face
        {0.5f, 0.5f, -0.5f},    // bot face
    };

    static std::vector<size_t> indices = 
    {
        0,1,2,
        2,3,0,
        4,5,6,
        6,7,4,
        8,9,10,
        10,11,8,
        12,13,14,
        14,15,12,
        16,17,18,
        18,19,16,
        20,21,22,
        22,23,20,
    };

    static glm::vec3 normal[] = {
        {0.0, -1.0, 0.0},  // front
        {0.0, -1.0, 0.0},  // front
        {0.0, -1.0, 0.0},  // front
        {0.0, -1.0, 0.0},  // front
        {0.0, 1.0, 0.0},   // back
        {0.0, 1.0, 0.0},   // back
        {0.0, 1.0, 0.0},   // back
        {0.0, 1.0, 0.0},   // back
        {-1.0, 0.0, 0.0},  // left
        {-1.0, 0.0, 0.0},  // left
        {-1.0, 0.0, 0.0},  // left
        {-1.0, 0.0, 0.0},  // left
        {1.0, 0.0, 0.0},   // right
        {1.0, 0.0, 0.0},   // right
        {1.0, 0.0, 0.0},   // right
        {1.0, 0.0, 0.0},   // right
        {0.0, 0.0, 1.0},   // top
        {0.0, 0.0, 1.0},   // top
        {0.0, 0.0, 1.0},   // top
        {0.0, 0.0, 1.0},   // top
        {0.0, 0.0, -1.0},  // bot
        {0.0, 0.0, -1.0},  // bot
        {0.0, 0.0, -1.0},  // bot
        {0.0, 0.0, -1.0},  // bot
    };

    std::cout << "size of normal " << sizeof(normal) / sizeof(float) / 3
              << std::endl;
    std::cout << "size of indices " << indices.size() << std::endl;

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glShadeModel(GL_FLAT);

    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glEnableClientState(GL_NORMAL_ARRAY);
    glNormalPointer(GL_FLOAT, 0, normal);


    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    glEnable(GL_DEPTH_TEST);
    // glm::vec4 light_pos{1.0f, 1.0f, 1.0f, 0.0f};
    // glLightfv(GL_POSITION, GL_LIGHT0, glm::value_ptr(light_pos));

    // glMatrixMode(GL_MODELVIEW);
    // glLoadIdentity();
    // glLoadMatrixf(glm::value_ptr(glm::lookAt()));

    // render loop
    // -----------
    while (!glfwWindowShouldClose(window))
    {
        // input
        // -----
        processInput(window);

        // render
        // ------
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // glViewport(0, 0, m_width / 4, m_height / 4);

        // glEnableClientState(GL_NORMAL_ARRAY);
        glColor3f(1.0f, 0.0f, 0.0f);

        glPushMatrix();
        glRotatef(30.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(30.0f, 1.0f, 0.0f, 0.0f);
        // glTranslatef(0.0f, 0.0f, -1.0f);
        // glDrawArrays(GL_TRIANGLES, 0, indices.size());  // this call should output an orange triangle
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, indices.data());
        // glDisableClientState(GL_VERTEX_ARRAY);
        glPopMatrix();

        // glViewport(m_width / 2, 0, m_width / 2, m_height);
        // glEnableClientState(GL_VERTEX_ARRAY);
        // glVertexPointer(3, GL_FLOAT, 0, secondTriangle);
        // glColor3f(0.0f, 1.0f, 0.0f);
        // glDrawArrays(GL_TRIANGLES, 0, 3);  // this call should output an orange triangle
        // glDisableClientState(GL_VERTEX_ARRAY);


        // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
        // -------------------------------------------------------------------------------
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // glfw: terminate, clearing all previously allocated GLFW resources.
    // ------------------------------------------------------------------
    glfwTerminate();
    return 0;
}

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

// glfw: whenever the window size changed (by OS or user resize) this callback function executes
// ---------------------------------------------------------------------------------------------
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // float ratio = float(width) / float(height);
    // // glFrustum(-0.5F,0.5F,-0.5F,0.5F,1.0F,3.0F);
    // glOrtho(-1.0f * ratio, 1.0f * ratio, -1.0f, 1.0f, -10.0f, 10.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    // glTranslatef(0.0, 0.0f, -2.0f);

    m_width = width;
    m_height = height;
}