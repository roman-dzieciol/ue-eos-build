#!/bin/bash

set -x
set -e
set -u
set -o pipefail

export LANG=C.UTF-8

export SCRIPT_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )"

export EOS_IOS_VERSION=$(cat "$SCRIPT_DIR/../eos-version.txt" | tr -d '[:space:]')
export EOS_FW_SUB_DIR="SDK/Bin/IOS"
export EOS_FW_NAME="EOSSDK.framework"
export EOS_XCFW_NAME="EOSSDK.xcframework"
export EOS_INPUT_DIR="/d/_Eos/_Input"
export EOS_OUTPUT_DIR="/d/_Eos/_Output"

export FW_PATH="$EOS_IOS_VERSION/$EOS_FW_SUB_DIR/$EOS_FW_NAME"
export FW_DIR="$EOS_INPUT_DIR/../../$FW_PATH"
export HEADERS_DIR="$FW_DIR/Headers"
export OUTPUT_DIR="$EOS_OUTPUT_DIR/Temp"
export OUTPUT_FW_IOS_ARM64_DIR="$OUTPUT_DIR/$EOS_IOS_VERSION/ios-arm64/$EOS_FW_NAME"
export OUTPUT_HEADERS_DIR="$OUTPUT_FW_IOS_ARM64_DIR/Headers"
export OUTPUT_XCFW_DIR="$OUTPUT_DIR/$EOS_IOS_VERSION/$EOS_XCFW_NAME"
export OUTPUT_AST_DIR="$OUTPUT_DIR/$EOS_IOS_VERSION/AST"

export CLANG_ARGS=" -femit-all-decls -Xpreprocessor -femit-all-decls -Xclang -femit-all-decls -Xpreprocessor -CC -Xpreprocessor -C -Xpreprocessor -dD  -Xclang -fno-eliminate-unused-debug-types -std=gnu11 -fparse-all-comments --verbose -F$OUTPUT_FW_IOS_ARM64_DIR/../"

# recreate AST dir
if [[ -d "$OUTPUT_AST_DIR" ]]; then
  rm -r "$OUTPUT_AST_DIR"
fi
if [[ ! -d "$OUTPUT_AST_DIR" ]]; then
  mkdir -p "$OUTPUT_AST_DIR"
fi

# emit preprocessed header
# this is currently needed to preserve some of the comments
clang -E -C -CC -dD --no-line-commands $CLANG_ARGS $OUTPUT_HEADERS_DIR/eos_umbrella.h > $OUTPUT_AST_DIR/eos_preprocessed_header.h

# emit preprocessed header without comments, for debugging
clang -E -dD --no-line-commands $CLANG_ARGS $OUTPUT_HEADERS_DIR/eos_umbrella.h > $OUTPUT_AST_DIR/eos_preprocessed_header_without_comments.h

# emit json ast, as input for swift-eos-build
clang -Xclang -ast-dump=json $CLANG_ARGS $OUTPUT_AST_DIR/eos_preprocessed_header.h > $OUTPUT_AST_DIR/EOSSDK.ast.json

# emit textual ast, for debugging
clang -Xclang -ast-dump -fno-color-diagnostics $CLANG_ARGS $OUTPUT_AST_DIR/eos_preprocessed_header.h > $OUTPUT_AST_DIR/EOSSDK.ast.txt
