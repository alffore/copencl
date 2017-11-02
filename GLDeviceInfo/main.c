//
//  main.c
//  GLDeviceInfo
//
//  Created by A. Alfonso Flores Reyes on 21/12/13.
//  Copyright (c) 2013 A. Alfonso Flores Reyes. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <OpenCL/opencl.h>

int main(int argc, const char * argv[])
{
    int err;
    
    cl_device_id device_id;
    //cl_context context;
    
    char nombre[1024];
    size_t tambuffer=0;
    
    cl_uint unidades;
    
    cl_ulong memoria;
    
    int gpu=1;
    err=clGetDeviceIDs(NULL, gpu?CL_DEVICE_TYPE_GPU:CL_DEVICE_TYPE_CPU,1, &device_id, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    
    err=clGetDeviceInfo(device_id,CL_DEVICE_NAME, 1024,&nombre, &tambuffer);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    printf("CL_DEVICE_NAME: %s (%zu)\n",nombre,tambuffer);

    err=clGetDeviceInfo(device_id,CL_DEVICE_MAX_COMPUTE_UNITS, sizeof(unidades),&unidades, NULL);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    printf("CL_DEVICE_MAX_COMPUTE_UNITS: %u\n",unidades);
    
    err=clGetDeviceInfo(device_id,CL_DEVICE_VERSION, 1024,&nombre, &tambuffer);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    printf("CL_DEVICE_VERSION: %s (%zu)\n",nombre,tambuffer);
    
    err=clGetDeviceInfo(device_id,CL_DEVICE_EXTENSIONS, 1024,&nombre, &tambuffer);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    printf("CL_DEVICE_EXTENSIONS: %s (%zu)\n",nombre,tambuffer);
    
    
    err=clGetDeviceInfo(device_id,CL_DEVICE_GLOBAL_MEM_SIZE, sizeof(memoria),&memoria, &tambuffer);
    if (err != CL_SUCCESS)
    {
        printf("Error: Failed to create a device group!\n");
        return EXIT_FAILURE;
    }
    printf("CL_DEVICE_GLOBAL_MEM_SIZE: %llu bytes (%zu)\n",memoria,tambuffer);
    
    
    return EXIT_SUCCESS;
}

