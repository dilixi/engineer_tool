
import os 
import argparse 
import glob

def replace_content(filename_replace,fname_content):
    with open(filename_replace, 'r', encoding='utf-8') as file:
        content = file.read()
    start_str = "/*RESOURCE_DEFINE_START*/"
    end_str = "/*RESOURCE_DEFINE_END*/"

    start_index = content.find(start_str)
    end_index = content.find(end_str)

    if start_index == -1 or end_index == -1:
        print("Start or end string not found.")
        return

    with open(fname_content, 'r', encoding='utf-8') as file:
         new_content = file.read()

    new_content = "\n" + new_content + "\n"
    new_content_length = len(new_content)
    #content = new_content
    content = content[:start_index + len(start_str)] + new_content + content[end_index:]

    with open(filename_replace, 'w', encoding='utf-8') as file:
        file.write(content) 

import os

# Function to generate the C file content based on the PNG filename
def generate_c_file_content(png_filename):
    # Remove the file extension and convert '-' or '.' to underscores
    variable_name = png_filename.replace('-', '_').replace('.', '_')
    
    c_content = f'''#include "../ui.h"

#ifndef LV_ATTRIBUTE_MEM_ALIGN
#define LV_ATTRIBUTE_MEM_ALIGN
#endif

#if !CONFIG_IMG_SRC_USING_FILE 
const LV_ATTRIBUTE_MEM_ALIGN uint8_t ui_img_{variable_name}_data[] = {{
}};

const lv_img_dsc_t ui_img_{variable_name} = {{
#else
lv_img_dsc_t ui_img_{variable_name} = {{
#endif   
   .header.always_zero = 0, 
   .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
   #if !CONFIG_IMG_SRC_USING_FILE
   .data_size = sizeof(ui_img_{variable_name}_data),
   .data = ui_img_{variable_name}_data
   #else
   .data = NULL
   #endif
}};
'''
    return c_content

# Function to process the PNG files in the source directory and output corresponding C files
def process_png_files(source_dir, output_dir):
    # Create the output directory if it doesn't exist
    os.makedirs(output_dir, exist_ok=True)

    # Traverse through all files in the source directory
    for filename in os.listdir(source_dir):
        if filename.endswith(".png"):
            # Generate the corresponding .c file name
            c_filename = f"ui_img_{filename.replace('-', '_').replace('.', '_')}.c"
            c_filepath = os.path.join(output_dir, c_filename)

            # Generate the content of the .c file
            c_content = generate_c_file_content(filename)

            # Write the content to the .c file in the output directory
            with open(c_filepath, 'w') as c_file:
                c_file.write(c_content)

            print(f"Generated {c_filepath}")


def delete_all_files_in_directory(directory):
    # 获取目录下的所有文件路径
    files = glob.glob(os.path.join(directory, "*"))
    
    # 遍历所有文件并删除
    for file in files:
        try:
            if os.path.isfile(file):
                os.remove(file)
                print(f"Deleted file: {file}")
        except Exception as e:
            print(f"Error deleting file {file}: {e}")


def build_image(dir_root):
    get_dir = "{0}/spiffs".format(dir_root)
    img_src_dir = "spiffs_pictures"
    c_out_dir = "out_imgs"
    delete_all_files_in_directory(get_dir)
    
    print("dir_root="+dir_root);
    print("img_src_dir="+img_src_dir);
    print("c_out_dir="+c_out_dir);
    #python lv_img_conv.py -f true_color_alpha -cf RGB565 -ff BIN -o inputfiles/spiffs -r spiffs_pictures
    #if os.name == 'nt':
    #    build_pictures="python lv_img_conv.py -f true_color_alpha -cf RGB565 -ff BIN -o {0}/spiffs -r spiffs_pictures".format(dir_root)
    #else:

    build_pictures="python3 lv_img_conv.py -f true_color_alpha -cf RGB565 -ff BIN -o {0}/spiffs -r spiffs_pictures".format(dir_root)
    
    os.system(build_pictures)  

    print("build_pictures="+build_pictures)
    if os.name == 'nt':
        build_copy_spiffs_ext="copy {0}/spiffs_ext/* {0}/spiffs -f".format(dir_root)
    else:
        build_copy_spiffs_ext="cp {0}/spiffs_ext/* {0}/spiffs -f".format(dir_root)

    os.system(build_copy_spiffs_ext)  
    #if os.name == 'nt':
    #    build_filesystem="combine_file.exe 2 {0} fat.bin fname_out.bin font_other spiffs".format(dir_root)
    #else:

    build_filesystem="./combine_file 2 {0} fat.bin fname_out.bin font_other spiffs".format(dir_root)
    
    os.system(build_filesystem)   
    filename = "../../../lib/utils_lib.h"
    content_file = "inputfiles/copy_to_project.txt" 
    replace_content(filename,content_file) 

    # Call the function to process PNG files and generate C files
    delete_all_files_in_directory(c_out_dir)
    process_png_files(img_src_dir, c_out_dir)
 
parser = argparse.ArgumentParser(description="Retro-Go build tool")

parser.add_argument(
# To do: Learn to use subcommands instead...
    "command", choices=["build-img", "build", "clean"],
) 
parser.add_argument(
    "--path", default="inputfiles", help="input path with file spiffs and spiffs_ext and so on"
)
args = parser.parse_args()
command = args.command
if command in ["build-img"]:
    print("=== Step: Packing ===\n")
    print("args.path="+args.path)
    build_image(args.path)
    
