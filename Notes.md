# Solution overview

* one C# project with Window Forms and GUI
    - compiled to MSIL, target x64
    - managed code
    - tasks
        - loads the image and display (eventual shrinking)
        - specifies the model file
        - runs detection
        - anotates picture
            - eventual 1 at a time
* one project C++/CLI 
    - compiled to MSIL, target x64
    - managed code(?), functions as bridge/wrapper
* one project native C++
    - compiled to native x64 code 
    - linked with supplied libraries
    - find out if this wrapper is necessary

# TODO

* which libraries to load
* mock detection, until Yolo is ready (in native C++)

# Be aware of the following

* native C++ is unmanaged, new/delete, keep track of memory
* C++/CLI:
    - managed or unmanaged?
* transfer of picture
    - pin the object, so GC does not move it
    - unpin after use
    - is that the same format? What is needed to receive it?
    - wrapper in C++/CLI or direct
* generated annotations
    - generated in native C++
    - marshalling / free structures in native C++
* YOLO has no C++ api - what is the proposed YOLO_CPP doing?
* ONNX instead?
* use unmanaged thread for the object detection - not interrupted by GC
* synchronization between C# and native C++
* coordinate system for bounding boxes

# Tests

* does native C++ run without interruptions?
* write C# loaded picture to file in C++ / data transfer works

# Thoughts

* Data that crosses the managed / unmanaged boundary is a risk.
The picture should have been loaded by opencv - the image classes are not compatible and a costly copy is needed.

* ONNX and OpenCV, but not Yolo: it seems that the referrred YOLO project only uses YOLO models, but the execution is totally based on the combination OpenCV (for the image part) and ONNX (for the neural network part). In addition, the cpp part reads the class names and uses them to paint the bounding boxes and annotate the picture.
