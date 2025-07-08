# Задаём содержимое для файла .clang-format
$clangFormatContent =
@"
---
# Updated for clang-format 12.0.1, some commented values are there
# for when we update to clang-format 13
Language:        Cpp
Standard:        c++20
BasedOnStyle:    LLVM

# The extra indent or outdent of access modifiers (e.g., public)
AccessModifierOffset: -4

# Align parameters on the open bracket
# someLongFunction(
#     argument1, argument2
# );
AlignAfterOpenBracket: BlockIndent

# Do not align all assigments
AlignConsecutiveAssignments:
   Enabled: false
   AcrossEmptyLines: false
   AcrossComments: false
   AlignCompound: false
   AlignFunctionDeclarations: false
   AlignFunctionPointers: false
   PadOperators: false

# Do not align all declarations
AlignConsecutiveDeclarations:
   Enabled: false
   AcrossEmptyLines: false
   AcrossComments: false
   AlignCompound: false
   AlignFunctionDeclarations: false
   AlignFunctionPointers: false
   PadOperators: false

#  #define SHORT_NAME       42
#  #define LONGER_NAME      0x007f   # does nice spacing for macros
AlignConsecutiveMacros:
    Enabled: true
    AcrossEmptyLines: true
    AcrossComments: false

# Do not align the colons of consecutive bitfields
AlignConsecutiveBitFields: None

# Align escaped newlines in macros - as far left as possible
AlignEscapedNewlinesLeft: Left

# Horizontally align operands of binary and ternary expressions
# Keeping the operand on the right edge of the upper line
AlignOperands: AlignAfterOperator

# Do not align consecutive comments that follow a line of code
AlignTrailingComments: true

# If a function call or braced initializer list doesn't fit on a line,
# allow putting all arguments onto the next line, even if
# BinPackArguments is false.
AllowAllArgumentsOnNextLine: false

# If a constructor definition with a member initializer list doesn't fit on a
# single line, allow putting all member initializers onto the next line, if
# ConstructorInitializerAllOnOneLineOrOnePerLine is true. Note that this parameter
# has no effect if ConstructorInitializerAllOnOneLineOrOnePerLine is false.
AllowAllConstructorInitializersOnNextLine: true

# If the function declaration doesn't fit on a line, allow putting all
# parameters of a function declaration onto the next line even if BinPackParameters.
AllowAllParametersOfDeclarationOnNextLine: false

# Short blocks (e.g., empty while loop, or a for loop that just continues) are
# never merged into a single line
AllowShortBlocksOnASingleLine: Never

# Short case labels are not contracted into a single line
AllowShortCaseLabelsOnASingleLine: false

# Short enums are not contracted into a single line
AllowShortEnumsOnASingleLine: false

# Short functions are not contracted into a single line
AllowShortFunctionsOnASingleLine: None

# Short If Statements are not contracted into a single line
AllowShortIfStatementsOnASingleLine: Never

# Short lambdas are not contracted into a single line
AllowShortLambdasOnASingleLine: None

# short loops are not contracted to a single line
AllowShortLoopsOnASingleLine: false

# Automatic - is by default (None is deprecated). Break depends on PenaltyReturnTypeOnItsOwnLine
AlwaysBreakAfterReturnType: Automatic

# do not always break before multiline string literals
AlwaysBreakBeforeMultilineStrings: true

# Always break after a template declaration
AlwaysBreakTemplateDeclarations: Yes

# A vector of strings that should be interpreted as attributes/qualifiers instead of identifiers.
# This can be useful for language extensions or static analyzer annotations
AttributeMacros: ['__capability', '__unused']

AlwaysBreakAfterDefinitionReturnType: None

# Function call arguments do not always have to have their own line if they don't
# fit on one line
BinPackArguments: false

# Function parameters do not always have to have their own line if they don't
# fit on one line
BinPackParameters: OnePerLine

# Add one space on each side of the :
BitFieldColonSpacing: Both

# Break after stuff like [[nodiscard]]
BreakAfterAttributes: Never

# Configure each individual brace in BraceWrapping.
BreakBeforeBraces: Custom
BraceWrapping:
    # Opening brace under case label
    AfterCaseLabel: true
    # Class brace opens on the same line as the class name
    AfterClass:      true
    # Braces are under control statement
    AfterControlStatement: Always
    # Braces are under enum
    AfterEnum:       true
    # Braces are under function prototype
    AfterFunction:   true
    # Braces are under namespace
    AfterNamespace:  true
    # Braces are under struct keyword
    AfterStruct:     true
    # Braces are under union keyword
    AfterUnion:      true
    # Braces are under extern keyword
    AfterExternBlock: true
    # Braces are under catch keyword
    BeforeCatch:     true
    # else keyword is placed under if close brace
    BeforeElse:      true
    # Place a trailing while loop below the close brace
    BeforeWhile:     true
    # Place \n before []() \n {}
    BeforeLambdaBody: true
    # Do not indent wrapped braces
    IndentBraces:    false
    # Empty function body braces are on multiple lines
    SplitEmptyFunction: true
    # Empty class/struct/union body braces are on multiple lines
    SplitEmptyRecord: true
    # Empty namespace body braces are on multiple lines
    SplitEmptyNamespace: true

# Break templates to separate strings
BreakTemplateDeclarations: Yes

# NOTE: Uncomment when clang-format verion 21
# BreakBeforeTemplateCloser: true

# For splitting long binary operations, break after the operator
BreakBeforeBinaryOperators: All

# Place concept declaration on a new line
BreakBeforeConceptDeclarations: true

# Break after the ternary operator - ?
BreakBeforeTernaryOperators: true

#
BreakBinaryOperations: OnePerLine

# Break constructor initializers after the colon and commas
BreakConstructorInitializers: BeforeComma

# If true, clang-format will always break before function definition parameters
BreakFunctionDefinitionParameters: false

# Break inheritance list after the colon and comma
BreakInheritanceList: BeforeComma

# Allow breaking long string literals into multiple lines
BreakStringLiterals: true

# Max Width of a line when formatting
ColumnLimit: 0

# A regular expression that describes comments with special meaning,
# which should not be split into lines or otherwise changed.
CommentPragmas:  '^ IWYU pragma:'

# Each namespace declaration is placed on a new line
CompactNamespaces: false

# Do not require initializers to be on their own lines when breaking
ConstructorInitializerAllOnOneLineOrOnePerLine: false

# The number of characters to use for indentation of constructor initializer
# lists as well as inheritance lists.
ConstructorInitializerIndentWidth: 4

# Indent width for line continuations.
ContinuationIndentWidth: 4

# format braced lists as best suited for C++11 braced lists
Cpp11BracedListStyle: false

# Analyze the formatted file for the most used line ending (\r\n or \n).
# UseCRLF is only used as a fallback if none can be derived.
DeriveLineEnding: true

# Do not read the file to derive pointer alignment requirements. Uses PointerAlignment value.
DerivePointerAlignment: false

# Do not completely disable formatting
DisableFormat:   false

# Add space right after private/public/etc
EmptyLineAfterAccessModifier: Always

# Add space right before private/public/etc
EmptyLineBeforeAccessModifier: Always

# If true, clang-format detects whether function calls and definitions are formatted with one parameter per line.
ExperimentalAutoDetectBinPacking: false

# add missing namespace end comments for short namespaces and fixes invalid existing ones.
FixNamespaceComments: true

# A vector of macros that should be interpreted as foreach loops instead of as function calls.
ForEachMacros: [ foreach, Q_FOREACH, BOOST_FOREACH ]

# Sort each #include block separately (blocks of includes are separated by empty lines)
IncludeBlocks:   Preserve

# Regular expressions denoting the different #include categories used for ordering #includes.
IncludeCategories:
    # Qt headers
    - Regex: '</Q([A-Za-z0-9-_])+>'
      Priority: 1
      # SortPriority: 0
      CaseSensitive: false
    # Qt headers
    - Regex: '<Q([A-Za-z0-9-_])+>'
      Priority: 2
      # SortPriority: 0
      CaseSensitive: false
    # google-tests
    - Regex: '^(<|"(gtest|gmock|isl|json|catch2|cmocka)/)'
      Priority: 3
      # SortPriority: 0
      CaseSensitive: false
    # GSL headers
    - Regex: '<([A-Za-z0-9-])+\/([A-Za-z0-9-])+>'
      Priority: 4
      # SortPriority: 0
      CaseSensitive: false

# Specify a regular expression of suffixes that are allowed in the file-to-main-include mapping.
# use this regex of allowed suffixes to the header stem.
# A partial match is done, so that: - "" means "arbitrary suffix" - "$" means "no suffix"
IncludeIsMainRegex: ''

# Specify a regular expression for files being formatted that are allowed to be considered
# "main" in the file-to-main-include mapping.
IncludeIsMainSourceRegex: ''

# access modifiers are indented (or outdented) relative to the record members,
# respecting the AccessModifierOffset
IndentAccessModifiers: false

# Do not indent case blocks one level from case label
IndentCaseBlocks: false

# Do indent case labels within a switch block
IndentCaseLabels: true

# Use AfterExternBlock's indenting rule
IndentExternBlock: AfterExternBlock

# Goto labels are indented to proper level
IndentGotoLabels: true

# Indents preprocessor directives before the hash.
IndentPPDirectives: None

# Indent requires clause in a template
IndentRequires: true

# Number of columns to use for indentation
IndentWidth:     4

# Indent if a function definition or declaration is wrapped after the type.
IndentWrappedFunctionNames: true

# Remove empty lines at the start of a block
KeepEmptyLines:
  AtEndOfFile: false
  AtStartOfBlock: true
  AtStartOfFile: true

# Align lambda body relative to the start of the lambda signature
LambdaBodyIndentation: Signature

# A regular expression matching macros that start a block.
MacroBlockBegin: ''

# A regular expression matching macros that end a block.
MacroBlockEnd:   ''

# Maximum number of consecutive empty lines to keep
MaxEmptyLinesToKeep: 1

# Don't indent namespaces
NamespaceIndentation: None

#
PackConstructorInitializers: NextLineOnly

# A vector of macros which are used to open namespace blocks
#NamespaceMacros: ''
PenaltyBreakAssignment: 2
PenaltyBreakBeforeFirstCallParameter: 19
PenaltyBreakComment: 300
PenaltyBreakFirstLessLess: 120
PenaltyBreakString: 1000
PenaltyBreakTemplateDeclaration: 10000
PenaltyExcessCharacter: 1000000
PenaltyBreakScopeResolution: 999999999 # Break before ::
PenaltyReturnTypeOnItsOwnLine: 999999999 # Break after return type
# PenaltyIndentedWhitespace: 1

# Align pointers: int* ptr
PointerAlignment: Left

# Align references like pointers: const auto& ref
ReferenceAlignment: Left

# Clang-format will attempt to reflow long comments
ReflowComments:  true

# Always have an ending namespace commment
ShortNamespaceLines: 0

# Include sorting is alphabetical and case insensitive
SortIncludes: true

# Using declarations will be  alphabetically sorted
SortUsingDeclarations: true

# Do not insert a space after a C-style cast
SpaceAfterCStyleCast: false

# Do not insert as pace after a logical not (!)
SpaceAfterLogicalNot: false

# Do not insert as pace after the template keyword
SpaceAfterTemplateKeyword: false

# Don't ensure spaces around pointer qualifiers, use PointerAlignment instead
SpaceAroundPointerQualifiers: Default

# Place spaces before assignment operators (=, +=, etc.)
SpaceBeforeAssignmentOperators: true

# Do not place a space befrore a case statement colon
SpaceBeforeCaseColon: false

# Do not place a space befrore a C++11 braced list
SpaceBeforeCpp11BracedList: false

# Do place a space between the constructor and the initializer colon
SpaceBeforeCtorInitializerColon: true

# Place a space between the class and the inheritance colon
SpaceBeforeInheritanceColon: true

# Control of individual space before parentheses
SpaceBeforeParens: Custom
SpaceBeforeParensOptions:
    AfterControlStatements: true
    AfterForeachMacros: true
    AfterFunctionDeclarationName: false
    AfterFunctionDefinitionName: false
    AfterIfMacros: true
    AfterOverloadedOperator: true
    AfterPlacementOperator: true
    AfterRequiresInClause: true
    AfterRequiresInExpression: true
    BeforeNonEmptyParentheses: false

# do not place a space before a range based for loop
SpaceBeforeRangeBasedForLoopColon: false

# do not place a space before square brackets []
SpaceBeforeSquareBrackets: false

# do not place a space in an empty block
SpaceInEmptyBlock: false

# Do not place a space in empty parens
SpacesInParens: Custom
SpacesInParensOptions:
    ExceptDoubleParentheses: false
    InConditionalStatements: false # Do not add spaces around if/for/while/switch conditions
    InCStyleCasts: true  # Do not add spaces in C-style cast parens
    InEmptyParentheses: false
    Other: false # Do not insert spaces after ( and before )

# Spaces between end of the code and the start of a // line comment
SpacesBeforeTrailingComments: 1

# Remove spaces within <> : <int>
SpacesInAngles: Never

# Do not insert spaces inside container literals
# var arr = [1, 2, 3];
# f({a: 1, b: 2, c: 3});
SpacesInContainerLiterals: false

# Do not insert spaces after [ and before ]
SpacesInSquareBrackets: false

# Macros which are ignored in front of a statement, as if they were an attribute.
StatementAttributeLikeMacros:

# A vector of macros that should be interpreted as complete statements.
#StatementMacros: ''

# The number of columns used for tab stops.
TabWidth: 4

# A vector of macros that should be interpreted as type declarations instead of as function calls.
#TypenameMacros: ''

# use \n for line breaks
UseCRLF: false

# Use tabs whenever we need to fill whitespace that spans at least from one tab stop to the next one.
UseTab:          Never

# The order in which the qualifiers appear
# QualifierOrder: ['inline', 'static', 'type', 'const', 'volatile' ]

# A vector of macros which are whitespace-sensitive and should not be touched.
WhitespaceSensitiveMacros:
  - STRINGIZE
  - PP_STRINGIZE
  - BOOST_PP_STRINGIZE
  - NS_SWIFT_NAME
  - CF_SWIFT_NAME
...
"@
