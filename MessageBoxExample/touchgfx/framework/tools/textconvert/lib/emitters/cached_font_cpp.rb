# Copyright (c) 2018(-2025) STMicroelectronics.
# All rights reserved.
#
# This file is part of the TouchGFX 4.25.0 distribution.
#
# This software is licensed under terms that can be found in the LICENSE file in
# the root directory of this software component.
# If no LICENSE file comes with this software, it is provided AS-IS.
#
###############################################################################/
class CachedFontCpp < Template
  def input_path
    File.join(root_dir,'Templates','CachedFont.cpp.temp')
  end
  def output_path
    '/src/CachedFont.cpp'
  end
  def output_filename
    File.join(@output_directory, output_path)
  end
  def run
    if !File::exists?(output_filename)
      #generate CachedFont.cpp
      super
    end
  end
end
