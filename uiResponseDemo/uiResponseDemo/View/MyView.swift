//
//  MyView.swift
//  uiResponseDemo
//
//  Created by lizihong on 2023/5/6.
//

import UIKit

/*
 用来测试点击方法，响应顺序的view
 
 点击此view，会按以下顺序打印
 调用 hitTest(_ point: CGPoint, with event: UIEvent?)
 调用 hitTest(_ point: CGPoint, with event: UIEvent?)
 调用 touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?)
 调用 viewDidTap(gesture: UITapGestureRecognizer)
 */
class MyView: UIView, UIGestureRecognizerDelegate {
    
    override init(frame: CGRect) {
        super.init(frame: frame)
        self.setup()
    }
    
    required init?(coder: NSCoder) {
        super.init(coder: coder)
    }
    
    func setup() {
//        let gesture = UITapGestureRecognizer.init(target: self, action: #selector(viewDidTap(gesture:)))
//        gesture.delegate = self
//        self.addGestureRecognizer(gesture)
        
        // 添加button后，会调用func buttonDidTap(button: UIButton)
        // 不调用 viewDidTap(gesture: UITapGestureRecognizer) 和 touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) 
//        let button = UIButton.init(frame: self.bounds)
//        button.autoresizingMask = [.flexibleWidth, .flexibleHeight]
//        button.addTarget(self, action: #selector(buttonDidTap(button:)), for: .touchUpInside)
//        self.addSubview(button)
//
//        // 能阻挡手势
//        let subView = UIButton.init(frame: self.bounds)
//        subView.backgroundColor = UIColor.white.withAlphaComponent(0.5)
//        subView.autoresizingMask = [.flexibleWidth, .flexibleHeight]
//        self.addSubview(subView)
    }
    
    @objc
    private func viewDidTap(gesture: UITapGestureRecognizer) {
        print("调用 viewDidTap(gesture: UITapGestureRecognizer)")
    }
    
    @objc
    private func buttonDidTap(button: UIButton) {
        print("调用 buttonDidTap(button: UIButton)")
    }

    override func touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?) {
        print("调用 View touchesBegan(_ touches: Set<UITouch>, with event: UIEvent?)")
        super.touchesBegan(touches, with: event)
        
    }
    
    override func hitTest(_ point: CGPoint, with event: UIEvent?) -> UIView? {
        print("调用 View hitTest(_ point: CGPoint, with event: UIEvent?)")
        return super.hitTest(point, with: event)
    }

}
