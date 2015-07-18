Pod::Spec.new do |s|
  s.name             = "ROKO.Mobi"
  s.version          = "0.2.0"
  s.license          = 'MPL'
  s.homepage         = "https://github.com/ROKOLabs/ROKO.Mobi.iOS"
  s.author           = "ROKO Labs"
  s.summary          = "ROKO.Mobi iOS SDK"
  s.description      = <<-DESC
The ROKO.Mobi SDK provides a means for taking photos, dressing them up in stickers, and sharing the results with the world through FB, Twitter, e-mail, or sms.
                       DESC

  s.source           = { :git => "https://github.com/ROKOLabs/ROKO.Mobi.iOS.git", :tag => s.version.to_s }
  s.social_media_url = 'https://twitter.com/rokolabs'
  s.platform         = :ios, '7.0'
  s.requires_arc     = true
  s.vendored_frameworks = 'SDK/ROKOMobi.framework'
  s.public_header_files = 'SDK/ROKOMobi.framework/Headers/*.h'
end