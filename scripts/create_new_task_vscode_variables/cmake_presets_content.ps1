# Задаём содержимое для файла CMakePresets.json
$cmakePresetsContent =
@"
{
    "version": 8,
    "configurePresets":
    [
        {
            "name": "windows-base",
            "description": "Target Windows with the Visual Studio Code development environment.",
            "hidden": true,
            "generator": "Ninja",
            "binaryDir": "`${sourceDir}/build",
            "cacheVariables":
            {
                "CMAKE_C_COMPILER": "cl.exe",
                "CMAKE_CXX_COMPILER": "cl.exe",
                "CMAKE_EXPORT_COMPILE_COMMANDS": "1",
                "CMAKE_CXX_STANDARD": "20",
                "CMAKE_BINARY_DIR": "`${sourceDir}/build",
                "CMAKE_PREFIX_PATH": ""
            },
            "environment": {
                "PATH": "`$penv{PATH}"
            },
            "condition":
            {
                "type": "equals",
                "lhs": "`${hostSystemName}",
                "rhs": "Windows"
            }
        },
        {
            "name": "x64-debug-win",
            "displayName": "x64-debug-win",
            "description": "Target Windows (64-bit) with the Visual Studio development environment. (Debug)",
            "inherits": "windows-base",
            "architecture":
            {
                "value": "x64",
                "strategy": "external"
            },
            "cacheVariables":
            {
                "CMAKE_BUILD_TYPE": "Debug"
            }
        },
        {
            "name": "x64-release-win",
            "displayName": "x64-release-win",
            "description": "Target Windows (64-bit) with the Visual Studio development environment. (RelWithDebInfo)",
            "inherits": "x64-debug-win",
            "cacheVariables":
            {
                "CMAKE_BUILD_TYPE": "Release"
            }
        },
        {
            "name": "x86-debug-win",
            "displayName": "x86-debug-win",
            "description": "Target Windows (32-bit) with the Visual Studio development environment. (Debug)",
            "inherits": "windows-base",
            "architecture":
            {
                "value": "x86",
                "strategy": "external"
            },
            "cacheVariables":
            {
                "CMAKE_BUILD_TYPE": "Debug"
            }
        },
        {
            "name": "x86-release-win",
            "displayName": "x86-release-win",
            "description": "Target Windows (32-bit) with the Visual Studio development environment. (RelWithDebInfo)",
            "inherits": "x86-debug-win",
            "cacheVariables":
            {
                "CMAKE_BUILD_TYPE": "Release"
            }
        },
        {
            "name": "linux-base",
            "displayName": "Linux Debug",
            "description": "For Linux",
            "generator": "Ninja",
            "binaryDir": "/home/heather/workspace/build/drill2_space_gui/gcc/vscode",
            "cacheVariables": {
                "CMAKE_C_COMPILER": "/usr/bin/gcc",
                "CMAKE_CXX_COMPILER": "/usr/bin/g++",
                "CMAKE_EXPORT_COMPILE_COMMANDS": "1",
                "CMAKE_BINARY_DIR": "`${sourceDir}/build",
                "CMAKE_PREFIX_PATH": ""
            },
            "condition":
            {
                "type": "equals",
                "lhs": "`${hostSystemName}",
                "rhs": "Linux"
            },
            "vendor":
            {
                "microsoft.com/VisualStudioSettings/CMake/1.0":
                {
                    "enableMicrosoftCodeAnalysis": false,
                    "disableExternalAnalysis": true,
                    "enableClangTidyCodeAnalysis": true,
                    "clangTidyChecks": "bugprone-*,clang-*,cppcoreguidelines-avoid-c-arrays,cppcoreguidelines-avoid-goto,cppcoreguidelines-avoid-magic-numbers,cppcoreguidelines-avoid-non-const-global-variables,cppcoreguidelines-avoid-reference-coroutine-parameters,cppcoreguidelines-c-copy-assignment-signature,cppcoreguidelines-explicit-virtual-functions,cppcoreguidelines-init-variables,cppcoreguidelines-interfaces-global-init,cppcoreguidelines-macro-usage,cppcoreguidelines-narrowing-conversions,cppcoreguidelines-no-malloc,cppcoreguidelines-non-private-member-variables-in-classes,cppcoreguidelines-prefer-member-initializer,cppcoreguidelines-pro-bounds-constant-array-index,cppcoreguidelines-pro-bounds-pointer-arithmetic,cppcoreguidelines-pro-type-*,cppcoreguidelines-slicing,cppcoreguidelines-special-member-functions,cppcoreguidelines-virtual-class-destructor,hicpp-avoid-*,hicpp-braces-around-statements,hicpp-deprecated-headers,hicpp-exception-baseclass,hicpp-explicit-conversions,hicpp-function-size,hicpp-invalid-access-moved,hicpp-member-init,hicpp-move-const-arg,hicpp-multiway-paths-covered,hicpp-new-delete-operators,hicpp-no-assembler,hicpp-no-malloc,hicpp-noexcept-move,hicpp-special-member-functions,hicpp-static-assert,hicpp-undelegated-constructor,hicpp-uppercase-literal-suffix,hicpp-use-*,hicpp-vararg,misc-confusable-identifiers,misc-definitions-in-headers,misc-misleading-*,misc-misplaced-const,misc-new-delete-overloads,misc-no-recursion,misc-non-copyable-objects,misc-redundant-expression,misc-static-assert,misc-throw-by-value-catch-by-reference,misc-unconventional-assign-operator,misc-uniqueptr-reset-release,misc-unused-*,misc-use-anonymous-namespace,modernize-avoid-*,modernize-concat-nested-namespaces,modernize-deprecated-*,modernize-loop-convert,modernize-macro-to-enum,modernize-make-*,modernize-pass-by-value,modernize-raw-string-literal,modernize-redundant-void-arg,modernize-replace-*,modernize-return-braced-init-list,modernize-shrink-to-fit,modernize-unary-static-assert,modernize-use-auto,modernize-use-bool-literals,modernize-use-emplace,modernize-use-equals-*,modernize-use-nodiscard,modernize-use-noexcept,modernize-use-nullptr,modernize-use-override,modernize-use-transparent-functors,modernize-use-uncaught-exceptions,modernize-use-using,readability-avoid-const-params-in-decls,readability-braces-around-statements,readability-const-return-type,readability-container-*,readability-delete-null-pointer,readability-duplicate-include,readability-else-after-return,readability-function-*,readability-identifier-naming,readability-implicit-bool-conversion,readability-inconsistent-declaration-parameter-name,readability-isolate-declaration,readability-magic-numbers,readability-make-member-function-const,readability-misleading-indentation,readability-misplaced-array-index,readability-non-const-parameter,readability-redundant-control-flow,readability-redundant-declaration,readability-redundant-function-ptr-dereference,readability-redundant-member-init,readability-redundant-preprocessor,readability-redundant-smartptr-get,readability-redundant-string-*,readability-simplify-*,readability-static-*,readability-string-compare,readability-suspicious-call-argument,readability-uniqueptr-delete-release,readability-uppercase-literal-suffix"
                }
            }
        },
        {
            "name": "x64-debug-linux",
            "displayName": "x64-debug-linux",
            "description": "Linux Debug",
            "inherits": "linux-base",
            "architecture":
            {
                "value": "x64",
                "strategy": "external"
            },
            "cacheVariables":
            {
                "CMAKE_BUILD_TYPE": "Debug"
            }
        }
    ],
    "buildPresets": [
        {
            "name": "x64-debug-win",
            "configurePreset": "x64-debug-win",
            "inheritConfigureEnvironment": true
        },
        {
            "name": "x64-debug-linux",
            "configurePreset": "x64-debug-linux",
            "inheritConfigureEnvironment": true
        }
    ],
    "testPresets": [
        {
            "name": "windows-core-test",
            "description": "Enable output on failure",
            "configurePreset": "windows-base",
            "hidden": false,
            "output":
            {
                "outputOnFailure": true
            }
        },
        {
            "name": "windows-base-test-x64-debug",
            "configurePreset": "x64-debug-win",
            "inherits": "windows-core-test",
            "hidden": false,
            "output":
            {
                "outputOnFailure": true
            },
            "execution":
            {
                "noTestsAction": "error",
                "stopOnFailure": false
            }
        }
    ]
}
"@
