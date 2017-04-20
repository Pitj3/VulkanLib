VULKAN_SDK_PATH = /home/pitje/Code/Vulkan/VulkanSDK/1.0.46.0/x86_64

CC := g++
CFLAGS := -std=c++11 -I$(VULKAN_SDK_PATH)/include
LDFLAGS := -L$(VULKAN_SDK_PATH)/lib `pkg-config --static --libs glfw3` -lvulkan -lGL -lGLU -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lXinerama -lXcursor

SRC := src/
OBJ := obj/

TARGET := VulkanLib

SOURCES := $(shell find $(SRC) -iname "*.cpp")
HEADERS := $(shell find $(SRC) -iname "*.hpp")
OBJECTS := $(patsubst $(SRC)%.cpp, $(OBJ)%.o, $(SOURCES))

.PHONY: all clean editCheck

all: clean $(TARGET)

run: all
	LD_LIBRARY_PATH=$(VULKAN_SDK_PATH)/lib VK_LAYER_PATH=$(VULKAN_SDK_PATH)/etc/explicit_layer.d @./$(TARGET)

$(OBJ)%.o: $(SRC)%.cpp
	@mkdir -p $(dir $@)
	$(CC) -c $< -o $@ $(CFLAGS)

$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	$(CC) $(OBJECTS) -o $(TARGET) $(LDFLAGS)

clean:
	$(RM) -rf $(BIN) $(OBJ)