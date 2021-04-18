#include <stdio.h>
#include <stdlib.h>
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#define CASEPRINTENUM(str) case str:\
            puts("    "#str);\
            break;\

#define MAX_ACTIVE_SOURCES 32

void printPathArray(int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    puts("\npathArray");
    for (int i = 0; i < numPathArrayElements; ++i) {
        DISPLAYCONFIG_PATH_INFO currentPath = pathArray[i];
        puts("sourceInfo");
        puts("  adapterId");
        printf("    adapterId.LowPart: %d\n", currentPath.sourceInfo.adapterId.LowPart);
        printf("    adapterId.HighPart: %ld\n", currentPath.sourceInfo.adapterId.HighPart);
        printf("  id: %d\n", currentPath.sourceInfo.id);
        printf("  modeInfoIdx: %d\n", currentPath.sourceInfo.modeInfoIdx);
        puts("  statusFlags");
        printf("    DISPLAYCONFIG_SOURCE_IN_USE: %d\n", DISPLAYCONFIG_SOURCE_IN_USE & currentPath.sourceInfo.statusFlags);
        puts("targetInfo");
        puts("  adapterId");
        printf("    adapterId.LowPart: %d\n", currentPath.targetInfo.adapterId.LowPart);
        printf("    adapterId.HighPart: %ld\n", currentPath.targetInfo.adapterId.HighPart);
        printf("  id: %d\n", currentPath.targetInfo.id);
        printf("  modeInfoIdx: %d\n", currentPath.targetInfo.modeInfoIdx);
        puts("  outputTechnology");
        switch (currentPath.targetInfo.outputTechnology) {
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_MIRACAST);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_WIRED);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INDIRECT_VIRTUAL);
            CASEPRINTENUM(DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL);
        }
        puts("  rotation");
        switch (currentPath.targetInfo.rotation) {
            CASEPRINTENUM(DISPLAYCONFIG_ROTATION_IDENTITY);
            CASEPRINTENUM(DISPLAYCONFIG_ROTATION_ROTATE90);
            CASEPRINTENUM(DISPLAYCONFIG_ROTATION_ROTATE180);
            CASEPRINTENUM(DISPLAYCONFIG_ROTATION_ROTATE270);
        }
        puts("  scaling");
        switch (currentPath.targetInfo.scaling) {
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_IDENTITY);
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_CENTERED);
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_STRETCHED);
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX);
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_CUSTOM);
            CASEPRINTENUM(DISPLAYCONFIG_SCALING_PREFERRED);
        }
        puts("  refreshRate");
        printf("    Numerator: %d\n", currentPath.targetInfo.refreshRate.Numerator);
        printf("    Denominator: %d\n", currentPath.targetInfo.refreshRate.Denominator);
        puts("  scanLineOrdering");
        switch (currentPath.targetInfo.scaling) {
            CASEPRINTENUM(DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED);
            CASEPRINTENUM(DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE);
            CASEPRINTENUM(DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST);
            CASEPRINTENUM(DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST);
        }
        printf("  targetAvailable: %d\n", currentPath.targetInfo.targetAvailable);
        puts("  statusFlags");
        printf("    DISPLAYCONFIG_SOURCE_IN_USE: %d\n", DISPLAYCONFIG_SOURCE_IN_USE & currentPath.sourceInfo.statusFlags);
        puts("flags");
        printf("  DISPLAYCONFIG_PATH_ACTIVE: %d\n", DISPLAYCONFIG_PATH_ACTIVE & currentPath.flags);
        printf("  DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE: %d\n", DISPLAYCONFIG_PATH_SUPPORT_VIRTUAL_MODE & currentPath.flags);
        puts("");
    }
}

void printModeInfoArray(int numModeInfoArrayElements, DISPLAYCONFIG_MODE_INFO *modeInfoArray) {
    puts("\nmodeInfoArray");
    for (int i = 0; i < numModeInfoArrayElements; ++i) {
        DISPLAYCONFIG_MODE_INFO currentModeInfo = modeInfoArray[i];
        puts("infoType");
        switch (currentModeInfo.infoType) {
            CASEPRINTENUM(DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE);
            CASEPRINTENUM(DISPLAYCONFIG_MODE_INFO_TYPE_TARGET);
            CASEPRINTENUM(DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE);
        }
        printf("id: %d\n", currentModeInfo.id);
        puts("adapterId");
        printf("  adapterId.LowPart: %d\n", currentModeInfo.adapterId.LowPart);
        printf("  adapterId.HighPart: %ld\n", currentModeInfo.adapterId.HighPart);
        switch (currentModeInfo.infoType) {
            case DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE: {
                puts("sourceMode");
                printf("  width: %d\n", currentModeInfo.sourceMode.width);
                printf("  height: %d\n", currentModeInfo.sourceMode.height);
                puts("  pixelFormat");
                switch (currentModeInfo.sourceMode.pixelFormat) {
                    CASEPRINTENUM(DISPLAYCONFIG_PIXELFORMAT_8BPP);
                    CASEPRINTENUM(DISPLAYCONFIG_PIXELFORMAT_16BPP);
                    CASEPRINTENUM(DISPLAYCONFIG_PIXELFORMAT_24BPP);
                    CASEPRINTENUM(DISPLAYCONFIG_PIXELFORMAT_32BPP);
                    CASEPRINTENUM(DISPLAYCONFIG_PIXELFORMAT_NONGDI);
                }
                puts("  position");
                printf("    x: %d\n", currentModeInfo.sourceMode.position.x);
                printf("    y: %d\n", currentModeInfo.sourceMode.position.y);
                break;
            }
            case DISPLAYCONFIG_MODE_INFO_TYPE_TARGET: {
                puts("targetMode");
                puts("  targetVideoSignalInfo");
                printf("    pixelRate: %llu\n", currentModeInfo.targetMode.targetVideoSignalInfo.pixelRate);
                puts("    hSyncFreq");
                printf("      Numerator: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.hSyncFreq.Numerator);
                printf("      Denominator: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.hSyncFreq.Denominator);
                puts("    vSyncFreq");
                printf("      Numerator: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.vSyncFreq.Numerator);
                printf("      Denominator: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.vSyncFreq.Denominator);
                puts("    activeSize");
                printf("      cx: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.activeSize.cx);
                printf("      cy: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.activeSize.cy);
                puts("    totalSize");
                printf("      cx: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.totalSize.cx);
                printf("      cy: %d\n", currentModeInfo.targetMode.targetVideoSignalInfo.totalSize.cy);
                break;
            }
            case DISPLAYCONFIG_MODE_INFO_TYPE_DESKTOP_IMAGE: {
                puts("desktopImageInfo <NOT SUPPORTED>");
                break;
            }
        }
        puts("");
    }
}

void printActiveDisplayInfo(int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray,
                            int numModeInfoArrayElements, DISPLAYCONFIG_MODE_INFO *modeInfoArray) {
    puts("Connected Active Monitor Info");
    puts("(Position Y increases downwards)");
    for (int i = 0; i < numPathArrayElements; ++i) {
        DISPLAYCONFIG_PATH_INFO currentPath = pathArray[i];
        if (!(DISPLAYCONFIG_PATH_ACTIVE & currentPath.flags)) continue;

        printf("Monitor Id: %d\n", currentPath.sourceInfo.id);
        for (int i = 0; i < numModeInfoArrayElements; ++i) {
            DISPLAYCONFIG_MODE_INFO currentModeInfo = modeInfoArray[i];
            if (currentModeInfo.id != currentPath.sourceInfo.id) continue;
            printf("Position: (%d, %d)\n",
                    currentModeInfo.sourceMode.position.x,
                    currentModeInfo.sourceMode.position.y
            );
            break;
        }
        for (int i = 0; i < numModeInfoArrayElements; ++i) {
            DISPLAYCONFIG_MODE_INFO currentModeInfo = modeInfoArray[i];
            if (currentModeInfo.id != currentPath.targetInfo.id) continue;
            printf("Resolution: %dx%d\n",
                    currentModeInfo.targetMode.targetVideoSignalInfo.activeSize.cx,
                    currentModeInfo.targetMode.targetVideoSignalInfo.activeSize.cy
            );
            break;
        }
        double refreshRateNumerator = (double) currentPath.targetInfo.refreshRate.Numerator;
        double refreshRateDenominator = (double) currentPath.targetInfo.refreshRate.Denominator;
        printf("Refresh Rate: %.6f\n", refreshRateNumerator / refreshRateDenominator);
        int outputTech = currentPath.targetInfo.outputTechnology;
        if (outputTech == DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI) {
            puts("Output Technology: HDMI");
        } else if (outputTech == DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI) {
            puts("Output Technology: DVI");
        } else if (outputTech == DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL) {
            puts("Output Technology: Display Port");
        } else {
            puts("Output Technology: Other");
        }
        puts("");
    }
}

int wasSuccessful(int result, char* methodName) {
    if (result != ERROR_SUCCESS) {
        printf("Could not %s, Error Code %d", methodName, result);
        switch (result) {
            CASEPRINTENUM(ERROR_SUCCESS);
            CASEPRINTENUM(ERROR_INVALID_PARAMETER);
            CASEPRINTENUM(ERROR_NOT_SUPPORTED);
            CASEPRINTENUM(ERROR_ACCESS_DENIED);
            CASEPRINTENUM(ERROR_GEN_FAILURE);
            CASEPRINTENUM(ERROR_INSUFFICIENT_BUFFER);
            CASEPRINTENUM(ERROR_BAD_CONFIGURATION);
        }
        return 0;
    }
    return 1;
}

void setDisplayConfigTopologySupplied(int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    int sharedConfigFlags = SDC_TOPOLOGY_SUPPLIED | SDC_ALLOW_PATH_ORDER_CHANGES;
    int result = SetDisplayConfig(numPathArrayElements, pathArray, 0, NULL, SDC_VALIDATE | sharedConfigFlags);
    if (!wasSuccessful(result, "SDC_VALIDATE SetDisplayConfig")) {
        return;
    } else {
        printf("VALID CONFIG\n");
    }

    result = SetDisplayConfig(numPathArrayElements, pathArray, 0, NULL, SDC_APPLY | sharedConfigFlags);
    if (!wasSuccessful(result, "SDC_APPLY SetDisplayConfig")) {
        return;
    } else {
        printf("APPLIED CONFIG\n");
    }
}

void enableMonitor(int sourceId, int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    int activeMonitors[MAX_ACTIVE_SOURCES];
    int numActiveSources = 0;
    for (int i = 0; i < numPathArrayElements; i++) {
        if (!pathArray[i].targetInfo.targetAvailable) {
            continue;
        }

        if (DISPLAYCONFIG_PATH_ACTIVE & pathArray[i].flags) {
            if (pathArray[i].sourceInfo.id >= MAX_ACTIVE_SOURCES) {
                printf("ONLY %d ACTIVE SOURCES SUPPORTED!", MAX_ACTIVE_SOURCES);
                return;
            }
            activeMonitors[pathArray[i].sourceInfo.id] = pathArray[i].targetInfo.id;
            numActiveSources++;
        }
    }

    int found = 0;
    for (int i = 0; i < numPathArrayElements; i++) {
        if (!pathArray[i].targetInfo.targetAvailable) {
            continue;
        }

        // Set modeInfoIdx of all active monitors to DISPLAYCONFIG_PATH_MODE_IDX_INVALID
        // This ensures SDC_TOPOLOGY_SUPPLIED will use database to fetch relative positions
        pathArray[i].sourceInfo.modeInfoIdx = DISPLAYCONFIG_PATH_MODE_IDX_INVALID;
        pathArray[i].targetInfo.modeInfoIdx = DISPLAYCONFIG_PATH_MODE_IDX_INVALID;

        if (pathArray[i].sourceInfo.id != sourceId) {
            continue;
        }

        for (int j = 0; j < numActiveSources; j++) {
            if (activeMonitors[j] == pathArray[i].targetInfo.id) {
                goto continueLable;
            }
        }

        printf("Enabling monitor %d (source %d)\n", pathArray[i].targetInfo.id, pathArray[i].sourceInfo.id);
        pathArray[i].flags = pathArray[i].flags | DISPLAYCONFIG_PATH_ACTIVE;
        found = 1;
        break;

        continueLable:;
    }

    if (!found) {
        printf("Could not find disabled monitor for source %d\n", sourceId);
        return;
    }

    setDisplayConfigTopologySupplied(numPathArrayElements, pathArray);
}

void disableMonitor(int sourceId, int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    int activeMonitors[MAX_ACTIVE_SOURCES];
    int found = 0;
    for (int i = 0; i < numPathArrayElements; i++) {
        if (!pathArray[i].targetInfo.targetAvailable) {
            continue;
        }

        // Set modeInfoIdx of all active monitors to DISPLAYCONFIG_PATH_MODE_IDX_INVALID
        // This ensures SDC_TOPOLOGY_SUPPLIED will use database to fetch relative positions
        pathArray[i].sourceInfo.modeInfoIdx = DISPLAYCONFIG_PATH_MODE_IDX_INVALID;
        pathArray[i].targetInfo.modeInfoIdx = DISPLAYCONFIG_PATH_MODE_IDX_INVALID;

        if (!(DISPLAYCONFIG_PATH_ACTIVE & pathArray[i].flags)) {
            continue;
        }

        if (pathArray[i].sourceInfo.id != sourceId) {
            continue;
        }

        printf("Disabling monitor %d (source %d)\n", pathArray[i].targetInfo.id, pathArray[i].sourceInfo.id);
        pathArray[i].flags = pathArray[i].flags & ~DISPLAYCONFIG_PATH_ACTIVE;
        found = 1;
    }

    if (!found) {
        printf("Could not find enabled monitor for source %d\n", sourceId);
        return;
    }

    setDisplayConfigTopologySupplied(numPathArrayElements, pathArray);
}

void toggleMonitor(int sourceId, int* forceEnable, int* forceDisable, int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    for (int i = 0; i < numPathArrayElements; i++) {
        if (!pathArray[i].targetInfo.targetAvailable) {
            continue;
        }
        
        if (!(DISPLAYCONFIG_PATH_ACTIVE & pathArray[i].flags)) {
            continue;
        }
        
        if (pathArray[i].sourceInfo.id == sourceId) {
            printf("Toggling source %d to DISABLED \n", sourceId);
            *forceDisable = 1;
            break;
        }
    }
    
    if (!*forceDisable && !*forceEnable) {
        printf("Toggling source %d to ENABLED \n", sourceId);
        *forceEnable = 1;
    }
}

int validSourceId(int sourceId, int numPathArrayElements, DISPLAYCONFIG_PATH_INFO *pathArray) {
    for (int i = 0; i < numPathArrayElements; i++) {
        if (!pathArray[i].targetInfo.targetAvailable) {
            continue;
        }
        
        if (pathArray[i].sourceInfo.id == sourceId) {
            return 1;
        }
    }
    
    printf("Could not find a source for id %d which is available\n", sourceId);
    return 0;
}

int main(int argc, char *argv[]) {
    int forceEnable = 0;    
    int forceDisable = 0;    
    int shouldPrintDisplayInfo = 0;
    int debug = 0;    
    int monitorSource = -1;
    if (argc == 1) {
        printf("Required Args: Monitor source as integer\n");
        printf("Optional Args: -e or -d to force enable or disable of monitor explicitly (default is toggle)\n");
        printf("Optional Args: -i to print active display info\n");
        printf("Optional Args: -debug to print full display config\n");
        return 1;
    }

    // 1st arg is always program name on windows
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-e") == 0) {
            forceEnable = 1;
        } else if (strcmp(argv[i], "-d") == 0) {
            forceDisable = 1;
        } else if (strcmp(argv[i], "-i") == 0) {
            shouldPrintDisplayInfo = 1;
        } else if (strcmp(argv[i], "-debug") == 0) {
            debug = 1;
        } else {
            monitorSource = atoi(argv[i]);
            if (monitorSource == 0 && strcmp(argv[i], "0") != 0) {
                printf("Could not parse arg '%s' as an int\n", argv[i]);
                return 1;
            }
        }
    }

    if (!debug && !shouldPrintDisplayInfo && monitorSource < 0) {
        printf("Required Args: Monitor source as integer\n");
        return 1;
    }

    if (!debug && forceEnable && forceDisable) {
        printf("Cannot both force enable and force disable, provide only 1 of -e or -d\n");
        return 1;
    }

    int numPathArrayElements, numModeInfoArrayElements;
    int flag = QDC_ALL_PATHS;
    int result;
    result = GetDisplayConfigBufferSizes(flag, &numPathArrayElements, &numModeInfoArrayElements);
    if (!wasSuccessful(result, "GetDisplayConfigBufferSizes")) {
        return result;
    }
    
    DISPLAYCONFIG_PATH_INFO *pathArray = malloc(numPathArrayElements * sizeof(DISPLAYCONFIG_PATH_INFO));
    DISPLAYCONFIG_MODE_INFO *modeInfoArray = malloc(numModeInfoArrayElements * sizeof(DISPLAYCONFIG_MODE_INFO));
    
    result = QueryDisplayConfig(flag, &numPathArrayElements, pathArray, &numModeInfoArrayElements, modeInfoArray, NULL);
    if (!wasSuccessful(result, "QueryDisplayConfig")) {   
        free(pathArray);
        free(modeInfoArray);
        return result;
    }
    
    if (debug) {
        puts("########################################################");
        puts("###                   PATH INFO                      ###");
        puts("########################################################");
        printPathArray(numPathArrayElements, pathArray);
        puts("");
        puts("########################################################");
        puts("###                   MODE INFO                      ###");
        puts("########################################################");
        printModeInfoArray(numModeInfoArrayElements, modeInfoArray);
        return 0;
    }
    
    if (shouldPrintDisplayInfo) {
        printActiveDisplayInfo(numPathArrayElements, pathArray, numModeInfoArrayElements, modeInfoArray);
        if (monitorSource < 0) {
            puts("No monitor ID provided exiting");
            return 0;
        }
    }

    if(!validSourceId(monitorSource, numPathArrayElements, pathArray)) {
        free(pathArray);
        free(modeInfoArray);
        return 1;
    }

    if (!(forceEnable || forceDisable)) {
        toggleMonitor(monitorSource, &forceEnable, &forceDisable, numPathArrayElements, pathArray);
    }

    if (forceEnable) {
        enableMonitor(monitorSource, numPathArrayElements, pathArray);
    } else if (forceDisable) {
        disableMonitor(monitorSource, numPathArrayElements, pathArray);
    }

    free(pathArray);
    free(modeInfoArray);

    return 0;
}
