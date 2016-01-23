#!/usr/bin/env python3.4

# cd module/pharo
# ./headerParser2Pharo.py ../python/src2/hdr_parser.py build headers.txt

import os,sys

if __name__ == '__main__':
    
    ROOT = os.path.dirname(os.path.realpath(__file__))
    hdr_parser_path = ROOT+"/../python/src2/hdr_parser.py"
    if len(sys.argv) > 1:
        hdr_parser_path = sys.argv[1]
    print(hdr_parser_path)
    sys.path.append(os.path.dirname(hdr_parser_path))
    import hdr_parser
    
    dstdir =  ROOT + "/build/"
    if len(sys.argv) > 2:
        dstdir = sys.argv[2]
    os.makedirs(dstdir,0o755,True)
    
    # srcfiles = hdr_parser.opencv_hdr_list
    # srcfileName = "../python3/headers.txt"
    srcfileName = "headers.txt"
    if len(sys.argv) > 3:
        srcfileName=sys.argv[3]    
    srcfiles = open(srcfileName, 'r').read().split(';')
          
    parser = hdr_parser.CppHeaderParser()
    
    decls = []
    for hname in srcfiles:
        decls += parser.parse(hname)
      
    decls_str='#(\n'
    for decl in decls:
        decl_str = str(decl)
        decl_str = decl_str.replace(',', ' ')
        decl_str = decl_str.replace('[', '(')
        decl_str = decl_str.replace(']', ')')
        decl_str="#"+decl_str
        decls_str+=decl_str+'\n'
    decls_str+=')'
    
    resultFile=open(dstdir+'/allDecls.st', 'w+')
    print(decls_str,file=resultFile)
      
    # parser.print_decls(decls)
    # print(len(decls))
    # print("namespaces:", " ".join(sorted(parser.namespaces)))
