Pod::Spec.new do |s|
  s.name             = "ROKO.Mobi"
  s.version          = "0.0.1"
  s.license          = 'MPL'
  s.homepage         = "https://github.com/ROKOLabs/ROKO.Mobi.iOS"
  s.authors          = { "Alexey Golovenkov" => "alexey.golovenkov@rokolabs.com",
                         "Denis Kempest" => "denis.kempest@rokolabs.com",  
                         "Sergey Maslov" => "sergey.maslov@rokolabs.com" }
  s.summary          = "Very well ROKO.Mobi."
  s.description      = <<-DESC
- 123
- 456
- 789
- etc
                       DESC

  s.source           = { :git => "https://github.com/ROKOLabs/ROKO.Mobi.iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/rokolabs'
  s.platform         = :ios, '7.0'
  s.requires_arc     = true
  s.vendored_frameworks = 'SDK/ROKOMobi.framework'
  s.public_header_files = 'SDK/ROKOMobi.framework/Versions/A/Headers/*.h'
  s.resource_bundles = {'ROKOMobi' => ['SDK/ROKOMobiResources.bundle']}  
end
