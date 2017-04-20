#include "VulkanLib.hpp"

class VulkanApp 
{
    public:
        void run() 
        {
            initWindow();
            initVulkan();
            mainLoop();
        }

    private:
        Display* display;

        void initWindow() 
        {
            display = new Display(800, 600);
            VulkanEngine::get()->setDisplay(display);
        }

        void initVulkan() 
        {
            VulkanEngine::get()->addValidationLayer("VK_LAYER_LUNARG_standard_validation");
            VulkanEngine::get()->createVulkanInstance();
            VulkanEngine::get()->createDebugCallback();
        }

        void mainLoop() 
        {
            while (VulkanEngine::get()->isRunning()) 
            {
                
                display->swapBuffers();
                glfwPollEvents();
            }

            delete display;
            VulkanEngine::destroy();
        }
};

int main() 
{
    VulkanApp app;

    try 
    {
        app.run();
    } 
    catch (const std::runtime_error& e) 
    {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}