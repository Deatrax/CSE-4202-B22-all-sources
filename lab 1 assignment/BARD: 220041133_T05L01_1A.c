#include <stdio.h>

#define MAX_DEVICES 32

int main() {
  int N, M, problemType, device1, device2, dependentDevice;
  unsigned int switchState = 0; // Bit mask for device states (1 = on, 0 = off)

  // Get number of devices and initial state
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    int state;
    scanf("%d", &state);
    switchState |= (state << i); // Set bit based on initial state
  }

  // Get number of problems
  scanf("%d", &M);

  // Process each problem
  for (int i = 0; i < M; i++) {
    scanf("%d %d %d", &problemType, &device1, &device2);

    switch (problemType) {
      case 1: // Overload   00110011
        switchState ^= (1 << device1) | (1 << device2); // Invert both bits
        break;
      case 2: // Melted Wiring
        switchState |= (1 << device1) | (1 << device2); // Turn both on
        break;
      case 3: // Wrongly Wired
        dependentDevice = device1;
        device1 = device2;
        if ((switchState & (1 << dependentDevice)) >> dependentDevice) { // Dependent device on
          switchState &= ~(1 << device1); // Turn off device1
        } else { // Dependent device off
          switchState |= (1 << device1); // Turn on device1
        }
        break;
    }
  }

  // Calculate and print number of active devices
  int activeDevices = 0;
  for (int i = 0; i < N; i++) {
    if ((switchState & (1 << i)) >> i) {
      activeDevices++;
    }
  }

  // Print final state and active devices
  for (int i = 0; i < N; i++) {
    printf("%d", (switchState & (1 << i)) >> i);
  }
  printf("\n%d\n", activeDevices);

  return 0;
}
