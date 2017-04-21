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
            VulkanEngine::get()->addDeviceExtension(VK_KHR_SWAPCHAIN_EXTENSION_NAME);

            VulkanEngine::get()->createVulkanInstance();
            VulkanEngine::get()->createDebugCallback();
            VulkanEngine::get()->createSurface();
            VulkanEngine::get()->createPhysicalDevice();
            VulkanEngine::get()->createLogicalDevice();
            VulkanEngine::get()->createSwapChain();
            VulkanEngine::get()->createImageViews();
            VulkanEngine::get()->createRenderPass();
            VulkanEngine::get()->createGraphicsPipeline();
            VulkanEngine::get()->createFramebuffers();
            VulkanEngine::get()->createCommandPool();
            VulkanEngine::get()->createCommandBuffers();
            VulkanEngine::get()->createSemaphores();
        }

        void mainLoop() 
        {
            while (VulkanEngine::get()->isRunning()) 
            {
                EventManager::get()->poll();
                VulkanEngine::get()->drawFrame();
            }

            vkDeviceWaitIdle(VulkanEngine::get()->_device);

            delete display;
            VulkanEngine::destroy();
            EventManager::destroy();
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