#include "Utility.h"

glm::vec3 ToRGB(unsigned int hexColor) {
    glm::vec3 rgbColor = {0, 0, 0};

    rgbColor.r = ((hexColor >> 16) & 0xFF) / 255.0;  // Extract the RR byte
    rgbColor.g = ((hexColor >> 8) & 0xFF) / 255.0;   // Extract the GG byte
    rgbColor.b = (hexColor & 0xFF) / 255.0;        // Extract the BB byte

    return rgbColor;
}

unsigned int ToHex(glm::vec3 rgbColor) {
    unsigned hexColor = 0;

    hexColor |= static_cast<int>(rgbColor.r * 255.0);
    hexColor <<= 8;
    hexColor |= static_cast<int>(rgbColor.g * 255.0);
    hexColor <<= 8;
    hexColor |= static_cast<int>(rgbColor.b * 255.0);

    return hexColor;
}