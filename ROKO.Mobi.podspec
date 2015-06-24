Pod::Spec.new do |s|
  s.name             = "ROKO.Mobi"
  s.version          = "0.1.2"
  s.license          = 'MPL'
  s.homepage         = "https://github.com/ROKOLabs/ROKO.Mobi.iOS"
  s.author           = "ROKO Labs"
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
  s.resource_bundles = {'ROKOMobiResources' => ['SDK/ROKOMobiResources.bundle/*']}  
end
