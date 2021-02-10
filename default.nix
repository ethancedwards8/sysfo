let
  pkgs = import <nixpkgs> {};
in
  with pkgs;

  stdenv.mkDerivation {
    pname = "sysfo";
    version = "1.0";

    src = ./.;

    buildPhase = ''
      make
    '';

    checkPhase = '' 
      $out/bin/sysfo -V > /dev/null
    '';

    installPhase = ''
      mkdir -p $out/bin
      cp sysfo $out/bin/sysfo
    '';
  }
