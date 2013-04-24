Pod::Spec.new do |s|
  s.name         = "FGallery-iPhone"
  s.version      = "1.3.0"
  s.summary      = "A CocoaPod for the FGallery-iPhone library."
  s.homepage     = "https://github.com/paulsfds/FGallery-iPhone"
  s.license      = 'MIT'
  s.author       = { "Paul Wong" => "paulsfds@gmail.com" }
  s.source       = { :git => "https://github.com/paulsfds/FGallery-iPhone.git", :tag => 'v1.3' }
  s.source_files = 'Classes'
  s.requires_arc = true
end
