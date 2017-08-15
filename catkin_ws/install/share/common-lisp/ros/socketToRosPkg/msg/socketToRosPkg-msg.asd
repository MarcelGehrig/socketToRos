
(cl:in-package :asdf)

(defsystem "socketToRosPkg-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :std_msgs-msg
)
  :components ((:file "_package")
    (:file "float64_header" :depends-on ("_package_float64_header"))
    (:file "_package_float64_header" :depends-on ("_package"))
  ))