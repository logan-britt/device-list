#include <vector>
#include <iostream>
#include <vulkan/vulkan.h>

int main()
{
  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pNext = nullptr;
  appInfo.apiVersion = VK_MAKE_VERSION(1, 1, 0);

  VkInstanceCreateInfo instInfo = {};
  instInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  instInfo.pNext = nullptr;
  instInfo.pApplicationInfo = &appInfo;
  instInfo.enabledLayerCount = 0;
  instInfo.ppEnabledLayerNames = nullptr;
  instInfo.enabledExtensionCount = 0;
  instInfo.ppEnabledExtensionNames = nullptr;
  instInfo.flags = 0;

  VkInstance instance;
  vkCreateInstance(&instInfo, nullptr, &instance);

  uint32_t physical_device_count;
  vkEnumeratePhysicalDevices(instance, &physical_device_count, nullptr);
  std::vector<VkPhysicalDevice> physical_devices(physical_device_count);
  vkEnumeratePhysicalDevices(instance, &physical_device_count, physical_devices.data());
  for(auto physical_device : physical_devices)
  {
    VkPhysicalDeviceProperties props;
    vkGetPhysicalDeviceProperties(physical_device, &props);
    std::cout << props.deviceName << std::endl;
  }

  vkDestroyInstance(instance, nullptr);
  return 0;
}