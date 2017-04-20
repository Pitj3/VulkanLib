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

        // Vulkan creation functions
        VkResult createDebugReportCallback(VkInstance instance, const VkDebugReportCallbackCreateInfoEXT* createInfo, const VkAllocationCallbacks* allocator, VkDebugReportCallbackEXT* callback);
        void destroyDebugReportCallback(VkInstance instance, VkDebugReportCallbackEXT callback, const VkAllocationCallbacks* allocator);

        void createVulkanInstance();
        void createDebugCallback();


        void setDisplay(Display* display);

        bool isRunning() { return _running; }

        void close();

    private:
        VulkanEngine();
        static VulkanEngine* instance;

        bool _running;

        Display* _display;

        // Vulkan members
        VkInstance _instance;
        VkDebugReportCallbackEXT _callback;
        std::vector<const char*> _validationLayers;

        // Vulkan functions
        bool checkValidationLayerSupport();
        std::vector<const char*> getRequiredExtensions();

};

#endif // VULKAN_ENGINE_H_