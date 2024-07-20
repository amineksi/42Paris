find . -type f -name '*.sh' -printf "%f\n" | awk '{gsub(/\.sh/,"");print}'
