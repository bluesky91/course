#include <iostream>
#include <spdlog/spdlog.h>
#include <GLFW/glfw3.h>

int main( int argc, const char **argv )
{

    // glfw ���̺귯�� �ʱ�ȭ, �����ϸ� ���� ����� ����
    SPDLOG_INFO("Initialize glfw");
    if (!glfwInit()) {
        const char* description = nullptr;
        glfwGetError(&description);
        SPDLOG_ERROR("failed to initialize glfw: {}", description);
        return -1;
    }

    // glfw ������ ����, �����ϸ� ���� ����� ����
    SPDLOG_INFO("Create glfw window");
    auto window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME,
      nullptr, nullptr);
    if (!window) {
        SPDLOG_ERROR("failed to create glfw window");
        glfwTerminate();
        return -1;
    }


    // glfw ���� ����, ������ close ��ư�� ������ ���� ����
    SPDLOG_INFO("Start main loop");
    while (!glfwWindowShouldClose(window)) 
    {
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
