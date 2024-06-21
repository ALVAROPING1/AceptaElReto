#include <bits/stdc++.h>

void radix_sort(unsigned int array[], unsigned int buffer[], size_t size) {
    size_t index[4][256] = {{0}}; // count / index matrix

    // Generate histograms: count the amount of values in the array with each
    // byte value on each position
    for (size_t i = 0; i < size; ++i) {
        uint32_t current = array[i];
        for (size_t j = 0; j < 4; ++j) {
            index[j][current & 0xff]++;
            current >>= 8;
        }
    }
    // Convert the counts to indices: for each byte position, replace each count
    // with the sum of the previous counts. This leaves at each position the
    // index of the first value
    for (size_t byte = 0; byte < 4; ++byte) {
        size_t total_items = 0;
        for (size_t i = 0; i < 256; ++i) {
            size_t n = index[byte][i];
            index[byte][i] = total_items;
            total_items += n;
        }
    }
    // Radix sort
    for (size_t byte = 0; byte < 4; ++byte) { // For each byte position
        // Sort the array by the current byte position (starting at the LSB)
        for (size_t i = 0; i < size; ++i) { // Iterate through the array
            // For each value, get the byte at the current byte position
            uint32_t current = array[i];
            size_t digit = (current >> (byte << 3)) & 0xff;
            // Store the value in the buffer at the position given by the index
            // matrix for the byte position/value, and increment it in
            // preparation for the next value
            buffer[index[byte][digit]++] = current;
        }
        // Swap the pointers to reuse the arrays without having to copy them
        std::swap(array, buffer);
    }
}

int main() {
    uint32_t arr[] = {1000, 500, 200, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    uint32_t buf[12] = {};
    radix_sort(arr, buf, 12);
    for (auto val : arr) {
        std::cout << val << " ";
    }
    return 0;
}
