#ifndef VULKAN_ENGINE_H_
#define VULKAN_ENGINE_H_

#include "Common.hpp"
#include "Display.hpp"

#include <vector>

class VulkanEngine
{
    public:
        ~VulkanEngine();

        static VulkanEngine* get();
        static void destroy();

        void addValidationLayer(const char* layer);
        void addDeviceExtension(const char* extension);

        // Vulkan creation functions
        VkResult createDebugReportCallback(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* createInfo, const VkAllocationCallbacks* allocator, VkDebugReportCallbackEXT* callback);
        void destroyDebugReportCallback(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* allocator);

        void createVulkanInstance();
        void createDebugCallback();
        void createSurface();
        void createPhysicalDevice();
        void createLogicalDevice();
        void createSwapChain();
        void createImageViews();
        void createRenderPass();
        void createGraphicsPipeline();
        void createFramebuffers();
        void createCommandPool();
        void createCommandBuffers();
        void createSemaphores();


        void drawFrame();


        void setDisplay(Display* display);
        Display* getDisplay() { return _display; }

        bool isRunning() { return _running; }

        void close();

        // BAD PROGRAMMER: TODO
        VkSurfaceKHR _surface;
        std::vector<const char*> _deviceExtensions;
        VkDevice _device;

    private:
        VulkanEngine();
        static VulkanEngine* instance;

        bool _running;

        Display* _display;

        // Vulkan members
        VkInstance _instance;
        VkDebugReportCallbackEXT _callback;
        

        VkPhysicalDevice _gpu = VK_NULL_HANDLE;

        VkQueue _graphicsQueue;
        VkQueue _presentQueue;

        VkSwapchainKHR _swapChain;
        std::vector<VkImage> _swapChainImages;
        VkFormat _swapChainImageFormat;
        VkExtent2D _swapChainExtent;
        std::vector<VkImageView> _swapChainImageViews;
        std::vector<VkFramebuffer> _swapChainFramebuffers;

        VkRenderPass _renderPass;
        VkPipelineLayout _pipelineLayout;
        VkPipeline _graphicsPipeline;

        VkCommandPool _commandPool;
        std::vector<VkCommandBuffer> _commandBuffers;

        VkSemaphore _imageAvailableSemaphore;
        VkSemaphore _renderFinishedSemaphore;

        std::vector<const char*> _validationLayers;

        // Vulkan functions
        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();

};

#endif // VULKAN_ENGINE_H_